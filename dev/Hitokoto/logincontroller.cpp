#include "logincontroller.h"
#include <QApplication>

LoginController::LoginController() : current_user(nullptr)
{
    User::setDefaultPath(QApplication::applicationDirPath().toStdString() + "/../../../resource/user.txt");
    User::loadFromFile();
}

LoginResult LoginController::Login(const QString& name, const QString& pwd) {
    try {
        current_user = User::verify(name.toStdString(), pwd.toStdString());
        if (current_user->isAdmin()) {
            return LoginResult::AdminLogin;
        } else {
            return LoginResult::TrivialLogin;
        }
    }  catch (const std::exception& e) {
        string error_msg = e.what();
        if (error_msg == "User does not exist!") {
            return LoginResult::UserDNE;
        } else if (error_msg == "Wrong user name or password!") {
            return LoginResult::WrongPwd;
        } else {
            //should not reach
            throw std::logic_error("unrecognized exception when login");
        }
    }
}

User* LoginController::getLoginUserPtr() const {
    return current_user;
}
