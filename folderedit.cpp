#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDir>
#include <QMessageBox>
#include <QFileDevice>
#include "folderedit.h"
#include "ui_folderedit.h"

FolderEdit::FolderEdit(const QString& basePath,const QStringList& path,Setting& s,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FolderEdit)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);
    ui->gridLayout->setContentsMargins(10, 10, 10, 10);
    baseFolder = basePath;
    folderTokens = path;
    setting = s;
    columns = setting.getColumnsAll();
    if(path.isEmpty())
    {
        isEdit = false;
    }
    initData();
}

FolderEdit::~FolderEdit()
{
    delete ui;
}
void FolderEdit::initData()
{
    if(isEdit)
    {
        this->setWindowTitle("编辑文件夹名称");
        //内容行
        for (int row = 0; row < columns.count(); ++row)
        {
            QLabel *label1 = new QLabel(columns[row]);
            controls.append(label1);
            label1->setMinimumSize(60,24);
            label1->setMaximumSize(60,24);
            ui->gridLayout->addWidget(label1, row, 0);
            if(columns[row]=="路径")
            {
                QLabel *label2 =new QLabel(folderTokens[row]);
                ui->gridLayout->addWidget(label2, row, 1);
            }
            else
            {
                QLineEdit *txt1 = new QLineEdit(folderTokens[row]);
                controls.append(txt1);
                ui->gridLayout->addWidget(txt1, row, 1);
            }
        }
    }
    else
    {
        this->setWindowTitle("新建文件夹");
        //内容行
        for (int row = 0; row < columns.count(); ++row)
        {
            QLabel *label1 = new QLabel(columns[row]);
            controls.append(label1);
            label1->setMinimumSize(60,24);
            label1->setMaximumSize(60,24);
            ui->gridLayout->addWidget(label1, row, 0);
            if(columns[row]=="路径")
            {
                QLabel *label2 = new QLabel();
                ui->gridLayout->addWidget(label2, row, 1);
            }
            else
            {
                QLineEdit *txt1 = new QLineEdit();
                controls.append(txt1);
                ui->gridLayout->addWidget(txt1, row, 1);
            }
        }
    }
    QPushButton *btnSave = new QPushButton("保存");
    connect(btnSave, &QPushButton::clicked,this,&FolderEdit::btnSaveClick);
    btnSave->setMinimumSize(80,24);
    btnSave->setMaximumSize(80,24);
    ui->gridLayout->addWidget(btnSave, columns.count(), 1);
    int height =(columns.count()+1)*35;
    this->resize(600,200);
}
//保存
void FolderEdit::btnSaveClick()
{
    QStringList tmp;
    int index=0;
    //遍历控件
    for(QWidget* c:controls)
    {
        if (QLineEdit* lineEdit = qobject_cast<QLineEdit*>(c))
        {
            if(columns[index]==setting.policy)
            {
                if(lineEdit->text()=="是")
                {
                    tmp.append(setting.policy);
                }
            }
            else
            {
                tmp.append(lineEdit->text());
            }
            index++;
        }
    }
    QString newName = QDir::cleanPath(baseFolder+"/"+tmp.join(setting.getSplit()));
    if(isEdit)  //编辑
    {
        QString oldName = QDir::cleanPath(folderTokens[folderTokens.count()-1]);
        editFolder(oldName,newName);
    }
    else //新建
    {
        newFolder(newName);
    }
}

//修改文件夹
void FolderEdit::editFolder(const QString& oldName,const QString& newName)
{
    QDir dir(oldName);
    dir.cdUp();
    // 检查源文件/目录是否存在
    if (!dir.exists(oldName)) {
        QMessageBox::warning(this,"操作提示","错误: 源文件/目录不存在:"+oldName);
        QDialog::reject();
        return;
    }

    // 检查目标文件/目录是否已存在
    if (dir.exists(newName)) {
        QMessageBox::warning(this,"操作提示","错误: 目标文件/目录已存在:"+newName);
        QDialog::reject();
        return;
    }

    // 检查源文件/目录是否可写
    QFileInfo info(oldName);
    if (!info.isWritable()) {
        QMessageBox::warning(this,"操作提示","错误: 源文件/目录不可写:"+oldName);
        QDialog::reject();
        return;
    }

    // 检查目标目录是否可写
    QFileInfo parentInfo(QFileInfo(newName).path());
    if (!parentInfo.isDir() || !parentInfo.isWritable()) {
        QMessageBox::warning(this,"操作提示","错误: 目标目录不可写或不存在:"+parentInfo.absoluteFilePath());
        QDialog::reject();
        return;
    }
    QFlags<QFileDevice::Permission> power = QFile::permissions(oldName);
    //判断文件所有者是否可读.
    if (power.testFlag(QFile::ReadOwner))
    {
        qDebug("可读!");
    }

    bool result = dir.rename(oldName,newName);
    if(result)
    {
        QMessageBox::information(this,"操作提示","修改成功");
        QDialog::accept();
    }
    else
    {
        QMessageBox::warning(this,"操作提示","修改失败");
        QDialog::reject();
    }
}
//新建文件夹
void FolderEdit::newFolder(const QString& newName)
{
    QDir dir(newName);
    dir.cdUp();
    // 检查源文件/目录是否存在
    if (dir.exists(newName)) {
        QMessageBox::warning(this,"操作提示","错误: 新建文件夹已经存在:"+newName);
        QDialog::reject();
        return;
    }
    bool result = dir.mkdir(newName);
    if(result)
    {
        QMessageBox::information(this,"操作提示","新建成功");
        QDialog::accept();
    }
    else
    {
        QMessageBox::warning(this,"操作提示","新建失败");
        QDialog::reject();
    }
}
