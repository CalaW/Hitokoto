/********************************************************************************
** Form generated from reading UI file 'adusermandialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADUSERMANDIALOG_H
#define UI_ADUSERMANDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_adUserManDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *adUserManDialog)
    {
        if (adUserManDialog->objectName().isEmpty())
            adUserManDialog->setObjectName(QString::fromUtf8("adUserManDialog"));
        adUserManDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(adUserManDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(adUserManDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, adUserManDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, adUserManDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(adUserManDialog);
    } // setupUi

    void retranslateUi(QDialog *adUserManDialog)
    {
        adUserManDialog->setWindowTitle(QCoreApplication::translate("adUserManDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adUserManDialog: public Ui_adUserManDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADUSERMANDIALOG_H
