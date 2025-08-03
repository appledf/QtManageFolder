#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <fstream>
#include <QWidget>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QStandardItemModel>
#include <QSettings>
#include <QMessageBox>
#include "Setting.h"
#include "AppSetting.h"
#include "folderedit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnChoose1_clicked();
    void on_btnChoose2_clicked();
    void on_btnRead1_clicked();
    void on_btnSetting_clicked();

    void on_btnRead2_clicked();

    void on_btnRerad1_clicked();

    void on_btnNew_clicked();

    void on_cbSubFolder_checkStateChanged(const Qt::CheckState &arg1);

private:
    Ui::Widget *ui;
    Setting setting;
    QList<QList<QString>> listData;
    QStandardItemModel *m_model;
    AppSetting *winSetting;
    QSettings *settings;
    QStringList columns;

    void loadSetting();
    void saveSetting();
    void initData();
    bool exportToCsv(const QString& filename,const QList<QString>& headers,const QList<QList<QString>>& listData);
    void loadFolderStructure(const QString &path);
    QStringList splitFolderName(const QString &folderPath);
    void showFolderEdit(const QModelIndex &index);
};
#endif // WIDGET_H
