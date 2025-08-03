#include "myfolder.h"

MyFolder::MyFolder()
{
}

QString MyFolder::toString()
{
    QString re= "";
    if(this->date.isEmpty())
    {
        return re;
    }
    re+= this->date;
    if(this->date.isEmpty())
    {
        return re;
    }
    re+=" "+this->brand;
    if(this->color.isEmpty())
    {
        return re;
    }
    re+=" "+this->color;
    if(this->user.isEmpty())
    {
        return re;
    }
    re+=" "+this->user;
    if(this->cellphone.isEmpty())
    {
        return re;
    }
    re+=" "+this->cellphone;
    if(this->other.isEmpty())
    {
        return re;
    }
    re+=" "+this->other;
    return re;
}
