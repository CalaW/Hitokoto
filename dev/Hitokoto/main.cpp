#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_window;
    LoginDialog login_dialog;

    main_window.show();

    QObject::connect(&login_dialog, SIGNAL(loginSuccess(LoginController)), &main_window, SLOT(loginDialogSuccess(LoginController)));
    QObject::connect(&main_window, SIGNAL(mainLoginBtnClicked()), &login_dialog, SLOT(showLoginDialog()));


//    if (login_dialog.exec() == QDialog::Accepted) {
//        main_window.show();
    return a.exec();
}
