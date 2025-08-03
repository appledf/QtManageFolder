/********************************************************************************
** Form generated from reading UI file 'folderedit.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOLDEREDIT_H
#define UI_FOLDEREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FolderEdit
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QDialog *FolderEdit)
    {
        if (FolderEdit->objectName().isEmpty())
            FolderEdit->setObjectName("FolderEdit");
        FolderEdit->resize(400, 300);
        gridLayoutWidget = new QWidget(FolderEdit);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(9, 9, 381, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(FolderEdit);

        QMetaObject::connectSlotsByName(FolderEdit);
    } // setupUi

    void retranslateUi(QDialog *FolderEdit)
    {
        FolderEdit->setWindowTitle(QCoreApplication::translate("FolderEdit", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FolderEdit: public Ui_FolderEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOLDEREDIT_H
