#ifndef APPSETTING_H
#define APPSETTING_H

#include <QDialog>
#include "setting.h"

namespace Ui {
class AppSetting;
}

class AppSetting : public QDialog
{
    Q_OBJECT

public:
    explicit AppSetting(Setting s,QWidget *parent = nullptr);
    ~AppSetting();
    Setting getData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AppSetting *ui;
    Setting setting;
};

#endif // APPSETTING_H
