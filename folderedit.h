#ifndef FOLDEREDIT_H
#define FOLDEREDIT_H

#include <QDialog>
#include <QList>
#include <QWidget>
#include "setting.h"

namespace Ui {
class FolderEdit;
}

class FolderEdit : public QDialog
{
    Q_OBJECT

public:
    explicit FolderEdit(const QString& basePath,const QStringList& folderTokens,Setting& s,QWidget *parent = nullptr);
    ~FolderEdit();

private:
    Ui::FolderEdit *ui;
    QString baseFolder;
    QStringList folderTokens;
    QStringList columns;
    QList<QWidget*> controls;
    QString folderPath;
    Setting setting;
    bool isEdit=true;

    void initData();
    void btnSaveClick();

    void editFolder(const QString& oldName,const QString& newName);
    void newFolder(const QString& newName);
};

#endif // FOLDEREDIT_H
