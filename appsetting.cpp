#include "appsetting.h"
#include "ui_appsetting.h"
#include "setting.h"

AppSetting::AppSetting(Setting s,QWidget *parent)
    : QDialog (parent)
    , ui(new Ui::AppSetting)
{
    ui->setupUi(this);
    setting = s;
    ui->txtFormat->setText(s.format);
}

AppSetting::~AppSetting()
{
    delete ui;
}

void AppSetting::on_pushButton_clicked()
{
    setting.format = ui->txtFormat->text();
    setting.split = "(空格)";
    setting.policy = "";
    setting.surplus = "2";
    setting.IsIncludeFile = "false";
    QDialog::accept();
}
Setting AppSetting::getData()
{
    return setting;
}

