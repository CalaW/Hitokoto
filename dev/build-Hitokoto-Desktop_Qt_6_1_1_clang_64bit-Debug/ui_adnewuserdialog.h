/********************************************************************************
** Form generated from reading UI file 'adnewuserdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADNEWUSERDIALOG_H
#define UI_ADNEWUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_adNewUserDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *newUserNameEdt;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *newUserPwdEdt;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *adNewUserDialog)
    {
        if (adNewUserDialog->objectName().isEmpty())
            adNewUserDialog->setObjectName(QString::fromUtf8("adNewUserDialog"));
        adNewUserDialog->resize(233, 138);
        gridLayout_2 = new QGridLayout(adNewUserDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        label_2 = new QLabel(adNewUserDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        newUserNameEdt = new QLineEdit(adNewUserDialog);
        newUserNameEdt->setObjectName(QString::fromUtf8("newUserNameEdt"));

        gridLayout->addWidget(newUserNameEdt, 1, 2, 1, 1);

        label = new QLabel(adNewUserDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 2, 1, 1);

        newUserPwdEdt = new QLineEdit(adNewUserDialog);
        newUserPwdEdt->setObjectName(QString::fromUtf8("newUserPwdEdt"));
        newUserPwdEdt->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(newUserPwdEdt, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(adNewUserDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(adNewUserDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, adNewUserDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, adNewUserDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(adNewUserDialog);
    } // setupUi

    void retranslateUi(QDialog *adNewUserDialog)
    {
        adNewUserDialog->setWindowTitle(QCoreApplication::translate("adNewUserDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("adNewUserDialog", "Password", nullptr));
        label->setText(QCoreApplication::translate("adNewUserDialog", "Username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adNewUserDialog: public Ui_adNewUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADNEWUSERDIALOG_H
