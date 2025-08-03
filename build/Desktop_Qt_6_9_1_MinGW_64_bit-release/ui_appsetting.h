/********************************************************************************
** Form generated from reading UI file 'appsetting.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPSETTING_H
#define UI_APPSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppSetting
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *txtFormat;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *AppSetting)
    {
        if (AppSetting->objectName().isEmpty())
            AppSetting->setObjectName("AppSetting");
        AppSetting->resize(434, 141);
        layoutWidget = new QWidget(AppSetting);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 411, 120));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        txtFormat = new QLineEdit(layoutWidget);
        txtFormat->setObjectName("txtFormat");

        gridLayout->addWidget(txtFormat, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(100, 24));
        pushButton->setMaximumSize(QSize(100, 24));

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);


        retranslateUi(AppSetting);

        QMetaObject::connectSlotsByName(AppSetting);
    } // setupUi

    void retranslateUi(QWidget *AppSetting)
    {
        AppSetting->setWindowTitle(QCoreApplication::translate("AppSetting", "\351\205\215\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("AppSetting", "\350\247\243\346\236\220\345\255\227\346\256\265\351\205\215\347\275\256\357\274\214\350\257\267\344\275\277\347\224\250\350\213\261\346\226\207\351\200\227\345\217\267\345\210\206\351\232\224", nullptr));
        label_5->setText(QCoreApplication::translate("AppSetting", "(\347\251\272\346\240\274)", nullptr));
        label_4->setText(QCoreApplication::translate("AppSetting", "\345\210\206\345\211\262\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("AppSetting", "\346\240\274\345\274\217\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("AppSetting", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppSetting: public Ui_AppSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPSETTING_H
