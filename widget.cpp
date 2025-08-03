#include "widget.h"
#include "ui_widget.h"
#include "appsetting.h"
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("文件夹管理V1.0      ★作者:走丢的大白,286403163@qq.com");
    this->setLayout(ui->gridLayout);
    ui->gridLayout->setContentsMargins(10, 10, 10, 10);
    //加载配置
    loadSetting();
    //初始化数据
    initData();
    // 连接双击信号到槽函数
    QObject::connect(ui->tableView, &QTableView::doubleClicked,
                     [&](const QModelIndex &index) {
                         showFolderEdit(index);
                     });
}

Widget::~Widget()
{
    delete ui;
}

///待读取路径定位
void Widget::on_btnChoose1_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(
        this, "选择文件夹", "", QFileDialog::ShowDirsOnly
        );
    if(!folderPath.isEmpty())
    {
        ui->txtFolder->setText(folderPath);
    }
}
//导出路径定位
void Widget::on_btnChoose2_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(
        this, "选择文件夹", "", QFileDialog::ShowDirsOnly
        );
    if(!folderPath.isEmpty())
    {
        ui->txtExport->setText(folderPath);
    }
}
//读取
void Widget::on_btnRead1_clicked()
{
    QString strDir = ui->txtFolder->text();
    if(strDir.isEmpty())
    {
        QMessageBox::warning(this,"警告","未选定路径无法读取");
        return;
    }
    if(setting.folderPath!=strDir)
    {
        setting.folderPath = strDir;
        saveSetting();
    }
    // 更新表格数据，清空现有数据
    listData.clear();
    m_model->removeRows(0, m_model->rowCount());
    // 获取根文件夹名称
    loadFolderStructure(strDir);

    // 添加人员数据到表格
    for(QList<QString> arr:listData)
    {
        QList<QStandardItem*> items;
        for(QString str:arr)
        {
            items.append(new QStandardItem(str));
        }
        m_model->appendRow(items);
    }
}
//设置
void Widget::on_btnSetting_clicked()
{
    winSetting = new AppSetting(setting,this);  // 创建对话框实例
    if(winSetting->exec()== QDialog::Accepted)
    {
        Setting data = winSetting->getData();
        //更新本地
        setting.folderPath = data.folderPath;
        setting.exportPath = data.exportPath;
        setting.format = data.format;
        setting.split = data.split;
        setting.policy = data.policy;
        setting.surplus = data.surplus;
        setting.IsIncludeFile = data.IsIncludeFile;
        saveSetting();
        initData();
        on_btnRead1_clicked();
    }

}
//导出
void Widget::on_btnRead2_clicked()
{
    QString exportFile = ui->txtExport->text();
    if(exportFile.isEmpty())
    {
        QMessageBox::warning(this,"警告","未选定导出路径无法导出");
        return;
    }
    if(listData.isEmpty())
    {
        QMessageBox::warning(this,"警告","无可导出数据无法导出");
        return;
    }
    if(setting.exportPath!=exportFile)
    {
        setting.exportPath = exportFile;
        saveSetting();
    }
    //时间转字符串
    QDateTime currentDateTime = QDateTime::currentDateTime();
    exportFile = ui->txtExport->text()+"/"+currentDateTime.toString("yyyyMMddHHmmss")+".csv";
    QList<QString> headers = setting.getColumns();
    if(setting.surplus=="2")
        headers.append("其他");
    bool result = exportToCsv(exportFile,headers,listData);
    if(result)
        QMessageBox::information(this,"提示","导出成功");
    else
        QMessageBox::warning(this,"提示","导出失败");
}
//新建
void Widget::on_btnNew_clicked()
{
    QString strDir = ui->txtFolder->text();
    FolderEdit fe(strDir,QStringList(),setting,this);
    if(fe.exec() == QDialog::Accepted)
    {
        on_btnRead1_clicked();
    }
}
//切换是否包含子文件夹
void Widget::on_cbSubFolder_checkStateChanged(const Qt::CheckState &arg1)
{
    on_btnRead1_clicked();
}


//加载配置
void Widget::loadSetting()
{
    try
    {
        // 指定INI文件路径和格式
        QString configPath=QCoreApplication::applicationDirPath()+"\\config.ini";
        settings = new QSettings(configPath, QSettings::IniFormat);

        setting.folderPath = settings->value("Group1/folder").toString();
        setting.exportPath = settings->value("Group1/export").toString();
        setting.format = settings->value("Group2/format").toString();
        setting.split = settings->value("Group2/split").toString();
        setting.policy = settings->value("Group2/policy").toString();
        setting.surplus = settings->value("Group2/surplus").toString();
        setting.IsIncludeFile = settings->value("Group2/IsIncludeFile","false").toString();
        //qDebug()<<"format："+setting.toString();
    }
    catch(const std::exception& e)
    {
        std::cerr << "捕获到异常: " << e.what() << '\n';
    }
}
//保存ini
void Widget::saveSetting()
{
    //qDebug()<<data.toString();
    settings->beginGroup("Group1");
    QDir dir = QDir(setting.folderPath);
    settings->setValue("folder",dir.absolutePath());
    dir = QDir(setting.exportPath);
    settings->setValue("export",dir.absolutePath());
    settings->endGroup();

    settings->beginGroup("Group2");
    settings->setValue("format",setting.format);
    settings->setValue("split",setting.split);
    settings->setValue("policy",setting.policy);
    settings->setValue("surplus",setting.surplus);
    settings->setValue("IsIncludeFile",setting.IsIncludeFile);
    settings->endGroup();
}
//初始化数据
void Widget::initData()
{
    //默认路径
    ui->txtFolder->setText(setting.folderPath);
    ui->txtExport->setText(setting.exportPath);
    //按钮图标
    ui->btnChoose1->setIcon(QIcon(":/icons/search.png"));
    ui->btnChoose1->setIconSize(QSize(20, 20));
    ui->btnChoose1->setObjectName("myQPushButton");
    ui->btnChoose2->setIcon(QIcon(":/icons/search.png"));
    ui->btnChoose2->setIconSize(QSize(20, 20));
    ui->btnChoose2->setObjectName("myQPushButton");
    ui->btnSetting->setIcon(QIcon(":/icons/setting.png"));
    ui->btnSetting->setIconSize(QSize(40, 40));
    ui->btnSetting->setObjectName("myQPushButton");
    //tableView
    m_model = new QStandardItemModel(0, 3, this);
    columns = setting.getColumnsAll();
    m_model->setHorizontalHeaderLabels(columns);
    ui->tableView->setModel(m_model);
    ui->tableView->setSortingEnabled(true);
    //设置整个列头的背景色
    ui->tableView->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "    background-color: #999999;"
        "    color: white;"
        "    padding-left: 4px;"
        "    border: 1px solid #6c6c6c;"
        "}"
        );
    //清空数据
    listData.clear();
    m_model->removeRows(0, m_model->rowCount());
}
//读取文件夹名称（包含子文件夹）
void Widget::loadFolderStructure(const QString& rootPath)
{
    qDebug()<<"目标文件夹："+rootPath;
    QString strFilter = ui->txtFilter->text();

    // 获取所有子文件夹
    QDir dir(rootPath);
    QFileInfoList subfolders = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    if(!subfolders.isEmpty())
    {
        for (const QFileInfo& folder : subfolders)
        {
            QStringList tmp= splitFolderName(folder.absoluteFilePath());
            if(!strFilter.isEmpty())
            {
                if(folder.absoluteFilePath().contains(strFilter))
                {
                    listData.append(tmp);
                }
            }
            else
            {
                listData.append(tmp);
            }
            //包含子文件夹
            if(ui->cbSubFolder->isChecked())
            {
                loadFolderStructure(folder.absoluteFilePath());
            }
        }
    }
}
//根据文件名构造数组
QStringList Widget::splitFolderName(const QString &folderPath)
{
    QDir dir(folderPath);
    QString name = dir.dirName();
    QStringList list = name.split(setting.getSplit());
    QStringList tmp;
    bool hasPolicy=false;
    int columnsCount = setting.getColumns().count();
    for(int i=0;i<columnsCount;i++)
    {
        if(i<list.count())
        {
            if(list.count()>i)
                tmp.append(list[i]);
            else
                tmp.append("");
        }
        else
            tmp.append("");
    }
    QString other="";
    if(list.count()>columnsCount)
    {
        for(int j=columnsCount;j<list.count();j++)
        {
            other+=list[j];
            if(j<list.count()-1)
            {
                other+=setting.getSplit();
            }
        }
    }
    if(setting.surplus=="0")
        tmp[tmp.count()-1] = tmp[tmp.count()-1]+setting.getSplit()+ other;
    else if(setting.surplus=="2")
        tmp.append(other);
    tmp.append(folderPath);
    return tmp;
}
//数据导出svc
bool Widget::exportToCsv(const QString& filePath,const QList<QString>& headers, const QList<QList<QString>>& data) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "错误", "无法打开文件: " + filePath);
        return false;
    }
    QTextStream stream(&file);
    // 添加BOM头（可选，用于Windows Excel识别UTF-8）
    stream << QChar(0xFEFF);
    //header
    QStringList escapedRow;
    for (const QString& field : headers) {
        // 转义双引号并添加引号
        QString escapedField = field;
        escapedField.replace("\"", "\"\"");
        escapedRow.append("\"" + escapedField + "\"");
    }
    stream << escapedRow.join(",") << "\n";
    // 写入数据
    for (const auto& row : data) {
        escapedRow.clear();
        for (const QString& field : row) {
            // 转义双引号并添加引号
            QString escapedField = field;
            escapedField.replace("\"", "\"\"");
            escapedRow.append("\"" + escapedField + "\"");
        }
        stream << escapedRow.join(",") << "\n";
    }

    file.close();
    return true;
}
//编辑
void Widget::showFolderEdit(const QModelIndex &index)
{
    if (index.isValid())
    {
        QString strDir = ui->txtFolder->text();
        QStandardItem* nameItem = m_model->item(index.row(), columns.count()-1);
        QString folder =  QString(nameItem->text());
        QStringList tmp = splitFolderName(folder);
        FolderEdit fe(strDir,tmp,setting,this);
        if(fe.exec() == QDialog::Accepted)
        {
            on_btnRead1_clicked();
        }
        /*
         QString text = QString("双击了第 %1 行，第 %2 列，内容为：%3")
                            .arg(index.row() + 1)
                            .arg(index.column() + 1)
                            .arg(index.data().toString());
         QMessageBox::information(ui->tableView, "双击事件", text);
        */
    }
}

