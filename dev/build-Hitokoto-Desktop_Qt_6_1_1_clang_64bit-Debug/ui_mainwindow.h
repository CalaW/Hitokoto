/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *welcomeLabel;
    QTableView *tableView;
    QWidget *widget;
    QVBoxLayout *mainPannelLay;
    QVBoxLayout *buttonLay;
    QPushButton *logioBtn;
    QPushButton *newBtn;
    QPushButton *adManageBtn;
    QPushButton *adDelHitoBtn;
    QVBoxLayout *viewOptionLay;
    QCheckBox *timeRangeCheck;
    QGridLayout *timeEdtLay;
    QDateTimeEdit *fromTimeEdt;
    QLabel *fromLabel;
    QDateTimeEdit *toTimeEdt;
    QLabel *toLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 350, 581, 221));
        QFont font;
        font.setFamilies({QString::fromUtf8("Source Han Serif SC")});
        font.setPointSize(80);
        font.setBold(true);
        label->setFont(font);
        label->setTextFormat(Qt::RichText);
        label->setTextInteractionFlags(Qt::NoTextInteraction);
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(630, 20, 121, 21));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 60, 541, 351));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(580, 70, 186, 227));
        mainPannelLay = new QVBoxLayout(widget);
        mainPannelLay->setObjectName(QString::fromUtf8("mainPannelLay"));
        mainPannelLay->setContentsMargins(0, 0, 0, 0);
        buttonLay = new QVBoxLayout();
        buttonLay->setObjectName(QString::fromUtf8("buttonLay"));
        logioBtn = new QPushButton(widget);
        logioBtn->setObjectName(QString::fromUtf8("logioBtn"));

        buttonLay->addWidget(logioBtn);

        newBtn = new QPushButton(widget);
        newBtn->setObjectName(QString::fromUtf8("newBtn"));

        buttonLay->addWidget(newBtn);

        adManageBtn = new QPushButton(widget);
        adManageBtn->setObjectName(QString::fromUtf8("adManageBtn"));

        buttonLay->addWidget(adManageBtn);

        adDelHitoBtn = new QPushButton(widget);
        adDelHitoBtn->setObjectName(QString::fromUtf8("adDelHitoBtn"));

        buttonLay->addWidget(adDelHitoBtn);


        mainPannelLay->addLayout(buttonLay);

        viewOptionLay = new QVBoxLayout();
        viewOptionLay->setObjectName(QString::fromUtf8("viewOptionLay"));
        timeRangeCheck = new QCheckBox(widget);
        timeRangeCheck->setObjectName(QString::fromUtf8("timeRangeCheck"));

        viewOptionLay->addWidget(timeRangeCheck);

        timeEdtLay = new QGridLayout();
        timeEdtLay->setObjectName(QString::fromUtf8("timeEdtLay"));
        fromTimeEdt = new QDateTimeEdit(widget);
        fromTimeEdt->setObjectName(QString::fromUtf8("fromTimeEdt"));

        timeEdtLay->addWidget(fromTimeEdt, 0, 1, 1, 1);

        fromLabel = new QLabel(widget);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));

        timeEdtLay->addWidget(fromLabel, 0, 0, 1, 1);

        toTimeEdt = new QDateTimeEdit(widget);
        toTimeEdt->setObjectName(QString::fromUtf8("toTimeEdt"));

        timeEdtLay->addWidget(toTimeEdt, 1, 1, 1, 1);

        toLabel = new QLabel(widget);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));

        timeEdtLay->addWidget(toLabel, 1, 0, 1, 1);


        viewOptionLay->addLayout(timeEdtLay);


        mainPannelLay->addLayout(viewOptionLay);

        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        logioBtn->raise();
        newBtn->raise();
        welcomeLabel->raise();
        tableView->raise();
        adManageBtn->raise();
        fromTimeEdt->raise();
        toTimeEdt->raise();
        toLabel->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<div style=\"color:gray\">\344\270\200\350\250\200\302\267\344\270\200\350\241\214\302\267\344\270\200\345\277\265</div>", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "\345\245\275\344\271\205\344\270\215\350\247\201\357\274\214", nullptr));
        logioBtn->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        newBtn->setText(QCoreApplication::translate("MainWindow", "new Hitokoto", nullptr));
        adManageBtn->setText(QCoreApplication::translate("MainWindow", "Manage User", nullptr));
        adDelHitoBtn->setText(QCoreApplication::translate("MainWindow", "Delete Hitokoto", nullptr));
        timeRangeCheck->setText(QCoreApplication::translate("MainWindow", "\346\214\211\346\227\266\351\227\264\350\214\203\345\233\264\346\237\245\347\234\213", nullptr));
        fromLabel->setText(QCoreApplication::translate("MainWindow", "\344\273\216", nullptr));
        toLabel->setText(QCoreApplication::translate("MainWindow", "\345\210\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
