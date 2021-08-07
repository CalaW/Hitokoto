/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
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
    QWidget *layoutWidget;
    QVBoxLayout *viewOptionLay;
    QPushButton *logioBtn;
    QPushButton *newBtn;
    QPushButton *adDelHitoBtn;
    QPushButton *adManageBtn;
    QCheckBox *timeRangeCheck;
    QGridLayout *timeEdtLay;
    QDateTimeEdit *fromTimeEdt;
    QDateTimeEdit *toTimeEdt;
    QLabel *toLabel;
    QLabel *fromLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 360, 581, 221));
        QFont font;
        font.setFamilies({QString::fromUtf8("Source Han Serif SC")});
        font.setPointSize(80);
        font.setBold(true);
        label->setFont(font);
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(false);
        label->setTextInteractionFlags(Qt::NoTextInteraction);
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(440, 0, 321, 41));
        welcomeLabel->setTextFormat(Qt::RichText);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(40, 60, 541, 351));
        tableView->setFrameShadow(QFrame::Raised);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setStretchLastSection(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(590, 90, 205, 218));
        viewOptionLay = new QVBoxLayout(layoutWidget);
        viewOptionLay->setObjectName(QString::fromUtf8("viewOptionLay"));
        viewOptionLay->setContentsMargins(0, 0, 0, 0);
        logioBtn = new QPushButton(layoutWidget);
        logioBtn->setObjectName(QString::fromUtf8("logioBtn"));
        logioBtn->setEnabled(true);
        logioBtn->setCheckable(false);
        logioBtn->setAutoDefault(true);
        logioBtn->setFlat(false);

        viewOptionLay->addWidget(logioBtn);

        newBtn = new QPushButton(layoutWidget);
        newBtn->setObjectName(QString::fromUtf8("newBtn"));

        viewOptionLay->addWidget(newBtn);

        adDelHitoBtn = new QPushButton(layoutWidget);
        adDelHitoBtn->setObjectName(QString::fromUtf8("adDelHitoBtn"));

        viewOptionLay->addWidget(adDelHitoBtn);

        adManageBtn = new QPushButton(layoutWidget);
        adManageBtn->setObjectName(QString::fromUtf8("adManageBtn"));

        viewOptionLay->addWidget(adManageBtn);

        timeRangeCheck = new QCheckBox(layoutWidget);
        timeRangeCheck->setObjectName(QString::fromUtf8("timeRangeCheck"));

        viewOptionLay->addWidget(timeRangeCheck);

        timeEdtLay = new QGridLayout();
        timeEdtLay->setObjectName(QString::fromUtf8("timeEdtLay"));
        fromTimeEdt = new QDateTimeEdit(layoutWidget);
        fromTimeEdt->setObjectName(QString::fromUtf8("fromTimeEdt"));
        fromTimeEdt->setEnabled(false);
        fromTimeEdt->setDateTime(QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)));
        fromTimeEdt->setDate(QDate(1970, 1, 1));
        fromTimeEdt->setMaximumDateTime(QDateTime(QDate(3000, 12, 31), QTime(23, 59, 59)));
        fromTimeEdt->setMinimumDateTime(QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)));

        timeEdtLay->addWidget(fromTimeEdt, 0, 1, 1, 1);

        toTimeEdt = new QDateTimeEdit(layoutWidget);
        toTimeEdt->setObjectName(QString::fromUtf8("toTimeEdt"));
        toTimeEdt->setEnabled(false);
        toTimeEdt->setDateTime(QDateTime(QDate(3000, 12, 31), QTime(23, 59, 59)));
        toTimeEdt->setMaximumDateTime(QDateTime(QDate(3000, 12, 31), QTime(23, 59, 59)));
        toTimeEdt->setMinimumDateTime(QDateTime(QDate(1970, 9, 14), QTime(0, 0, 0)));

        timeEdtLay->addWidget(toTimeEdt, 1, 1, 1, 1);

        toLabel = new QLabel(layoutWidget);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));

        timeEdtLay->addWidget(toLabel, 1, 0, 1, 1);

        fromLabel = new QLabel(layoutWidget);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));

        timeEdtLay->addWidget(fromLabel, 0, 0, 1, 1);


        viewOptionLay->addLayout(timeEdtLay);

        MainWindow->setCentralWidget(centralwidget);
        layoutWidget->raise();
        label->raise();
        welcomeLabel->raise();
        tableView->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        logioBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<div style=\"color:gray\">\344\270\200\350\250\200\302\267\344\270\200\350\241\214\302\267\344\270\200\345\277\265</div>", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Welcome,", nullptr));
        logioBtn->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        newBtn->setText(QCoreApplication::translate("MainWindow", "Publish Hitokoto", nullptr));
        adDelHitoBtn->setText(QCoreApplication::translate("MainWindow", "Delete Hitokoto", nullptr));
        adManageBtn->setText(QCoreApplication::translate("MainWindow", "Add User", nullptr));
        timeRangeCheck->setText(QCoreApplication::translate("MainWindow", "View by Time Range", nullptr));
        toLabel->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        fromLabel->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
