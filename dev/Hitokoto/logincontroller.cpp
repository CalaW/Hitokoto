#include "logincontroller.h"

LoginController::LoginController() : current_user(nullptr)
{

}

LoginResult LoginController::Login(const QString& name, const QString& pwd) {
    try {
        current_user = User::verify(name.toStdString(), pwd.toStdString());
    }  catch (const std::exception& e) {
        string error_msg = e.what();
        if (error_msg == "User does not exist!") {
            return LoginResult::UserDNE;
        } else if (error_msg == "Wrong user name or password!") {
            return LoginResult::WrongPwd;
        } else {
            throw std::logic_error("unrecognized exception when login");
        }
    }
}

User* LoginController::getLoginUserPtr() {
    return current_user;
}
