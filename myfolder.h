#ifndef MYFOLDER_H
#define MYFOLDER_H

#include <QString>

class MyFolder
{
public:
    MyFolder();

    QString date;
    QString brand;
    QString color;
    QString user;
    QString cellphone;
    QString other;
    QString path;

    QString toString();
};

#endif // MYFOLDER_H
