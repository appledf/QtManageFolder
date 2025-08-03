/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *txtFolder;
    QPushButton *btnChoose1;
    QPushButton *btnRead1;
    QPushButton *btnSetting;
    QLabel *label_2;
    QLineEdit *txtExport;
    QPushButton *btnChoose2;
    QPushButton *btnRead2;
    QLabel *label_3;
    QLineEdit *txtFilter;
    QCheckBox *cbSubFolder;
    QPushButton *btnNew;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(784, 600);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(8, 1, 771, 591));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtFolder = new QLineEdit(widget);
        txtFolder->setObjectName("txtFolder");

        gridLayout->addWidget(txtFolder, 0, 1, 1, 2);

        btnChoose1 = new QPushButton(widget);
        btnChoose1->setObjectName("btnChoose1");
        btnChoose1->setMinimumSize(QSize(30, 24));
        btnChoose1->setMaximumSize(QSize(30, 24));
        btnChoose1->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnChoose1->setIcon(icon);

        gridLayout->addWidget(btnChoose1, 0, 3, 1, 1);

        btnRead1 = new QPushButton(widget);
        btnRead1->setObjectName("btnRead1");
        btnRead1->setMinimumSize(QSize(60, 24));
        btnRead1->setMaximumSize(QSize(60, 24));

        gridLayout->addWidget(btnRead1, 0, 4, 1, 1);

        btnSetting = new QPushButton(widget);
        btnSetting->setObjectName("btnSetting");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSetting->sizePolicy().hasHeightForWidth());
        btnSetting->setSizePolicy(sizePolicy);
        btnSetting->setMinimumSize(QSize(50, 50));
        btnSetting->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/setting.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSetting->setIcon(icon1);
        btnSetting->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnSetting, 0, 5, 2, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        txtExport = new QLineEdit(widget);
        txtExport->setObjectName("txtExport");

        gridLayout->addWidget(txtExport, 1, 1, 1, 2);

        btnChoose2 = new QPushButton(widget);
        btnChoose2->setObjectName("btnChoose2");
        btnChoose2->setMinimumSize(QSize(30, 24));
        btnChoose2->setMaximumSize(QSize(30, 24));
        btnChoose2->setIcon(icon);

        gridLayout->addWidget(btnChoose2, 1, 3, 1, 1);

        btnRead2 = new QPushButton(widget);
        btnRead2->setObjectName("btnRead2");
        btnRead2->setMinimumSize(QSize(60, 24));
        btnRead2->setMaximumSize(QSize(60, 24));

        gridLayout->addWidget(btnRead2, 1, 4, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        txtFilter = new QLineEdit(widget);
        txtFilter->setObjectName("txtFilter");

        gridLayout->addWidget(txtFilter, 2, 1, 1, 1);

        cbSubFolder = new QCheckBox(widget);
        cbSubFolder->setObjectName("cbSubFolder");

        gridLayout->addWidget(cbSubFolder, 2, 2, 1, 1);

        btnNew = new QPushButton(widget);
        btnNew->setObjectName("btnNew");
        btnNew->setMinimumSize(QSize(60, 24));
        btnNew->setMaximumSize(QSize(60, 24));

        gridLayout->addWidget(btnNew, 2, 4, 1, 1);

        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(tableView, 3, 0, 1, 6);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\344\270\273\347\252\227\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\267\257\345\276\204", nullptr));
        btnChoose1->setText(QString());
        btnRead1->setText(QCoreApplication::translate("Widget", "\350\257\273\345\217\226", nullptr));
        btnSetting->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "\345\257\274\345\207\272", nullptr));
        btnChoose2->setText(QString());
        btnRead2->setText(QCoreApplication::translate("Widget", "\345\257\274\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\350\277\207\346\273\244", nullptr));
        cbSubFolder->setText(QCoreApplication::translate("Widget", "\345\214\205\345\220\253\345\255\220\346\226\207\344\273\266\345\244\271", nullptr));
        btnNew->setText(QCoreApplication::translate("Widget", "\346\226\260\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
