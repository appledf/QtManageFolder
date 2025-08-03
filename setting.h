#ifndef SETTING_H
#define SETTING_H
#include <QString>
#include <QStringList>

class Setting
{
public:
    Setting();
    QString folderPath;
    QString exportPath ;

    QString format ;
    QString split ;
    QString policy ;
    QString surplus ;
    QString IsIncludeFile ;

    QStringList getColumns();
    QStringList getColumnsAll();
    QStringList getPolicys();
    QString getSplit();
    int getPathIndex();
    QString toString();
};

#endif // SETTING_H
