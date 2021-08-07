/********************************************************************************
** Form generated from reading UI file 'dialognewhito.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNEWHITO_H
#define UI_DIALOGNEWHITO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogNewHito
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *newHitoTimeEdt;
    QSpacerItem *horizontalSpacer;
    QComboBox *newHitoTypeCombo;
    QTextEdit *newHitoContentEdt;

    void setupUi(QDialog *DialogNewHito)
    {
        if (DialogNewHito->objectName().isEmpty())
            DialogNewHito->setObjectName(QString::fromUtf8("DialogNewHito"));
        DialogNewHito->resize(515, 360);
        gridLayout = new QGridLayout(DialogNewHito);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(DialogNewHito);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogNewHito);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        newHitoTimeEdt = new QDateTimeEdit(DialogNewHito);
        newHitoTimeEdt->setObjectName(QString::fromUtf8("newHitoTimeEdt"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newHitoTimeEdt->sizePolicy().hasHeightForWidth());
        newHitoTimeEdt->setSizePolicy(sizePolicy);
        newHitoTimeEdt->setMaximumDateTime(QDateTime(QDate(3000, 12, 31), QTime(23, 59, 59)));
        newHitoTimeEdt->setMinimumDateTime(QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)));
        newHitoTimeEdt->setCalendarPopup(false);

        horizontalLayout->addWidget(newHitoTimeEdt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        newHitoTypeCombo = new QComboBox(DialogNewHito);
        newHitoTypeCombo->addItem(QString());
        newHitoTypeCombo->addItem(QString());
        newHitoTypeCombo->addItem(QString());
        newHitoTypeCombo->setObjectName(QString::fromUtf8("newHitoTypeCombo"));
        newHitoTypeCombo->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(newHitoTypeCombo);


        verticalLayout->addLayout(horizontalLayout);

        newHitoContentEdt = new QTextEdit(DialogNewHito);
        newHitoContentEdt->setObjectName(QString::fromUtf8("newHitoContentEdt"));

        verticalLayout->addWidget(newHitoContentEdt);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(DialogNewHito);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogNewHito, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogNewHito, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogNewHito);
    } // setupUi

    void retranslateUi(QDialog *DialogNewHito)
    {
        DialogNewHito->setWindowTitle(QCoreApplication::translate("DialogNewHito", "\346\267\273\345\212\240\350\250\200\302\267\345\277\265\302\267\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        DialogNewHito->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("DialogNewHito", "Time", nullptr));
        newHitoTimeEdt->setDisplayFormat(QCoreApplication::translate("DialogNewHito", "yyyy/M/d APh:mm", nullptr));
        newHitoTypeCombo->setItemText(0, QCoreApplication::translate("DialogNewHito", "a word", nullptr));
        newHitoTypeCombo->setItemText(1, QCoreApplication::translate("DialogNewHito", "an action", nullptr));
        newHitoTypeCombo->setItemText(2, QCoreApplication::translate("DialogNewHito", "a thought", nullptr));

        newHitoContentEdt->setPlaceholderText(QCoreApplication::translate("DialogNewHito", "\350\257\267\350\276\223\345\205\245\345\206\205\345\256\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogNewHito: public Ui_DialogNewHito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNEWHITO_H
