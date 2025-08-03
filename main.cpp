#include "widget.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //样式文件
    QFile styleFile(":/style/stylePushButton.qss");
    if(styleFile.open(QFile::ReadOnly)){
        QString styleSheet = QString(styleFile.readAll());
        a.setStyleSheet(styleSheet);
        styleFile.close();
    }
    //图标
    a.setWindowIcon(QIcon(":/icons/logo.png"));
    Widget w;
    w.show();
    return a.exec();
}
