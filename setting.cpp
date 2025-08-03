#include "setting.h"

Setting::Setting()
{
}
//转字符串
QString Setting::toString()
{
    QString re ="";
    re += folderPath+" ";
    re += exportPath+" ";
    re += format+" ";
    re += split+" ";
    re += policy+" ";
    re += surplus+" ";
    re += IsIncludeFile+" ";
    return re;
}
//获取指定字段
QStringList Setting::getColumns()
{
    return this->format.split(",");
}
//获取全部字段
QStringList Setting::getColumnsAll()
{
    QStringList re = this->format.split(",");
    //多余字段
    if(this->surplus=="2")
    {
        re.append("其他");
    }
    re.append("路径");
    return re;
}
//获取分隔符
QString Setting::getSplit()
{
    return split=="(空格)"?" ":split;
}
//路径所在列索引
int Setting::getPathIndex()
{
    int count = getColumnsAll().count();
    if(surplus=="2")
        count++;
    count++;
    return count;
}
