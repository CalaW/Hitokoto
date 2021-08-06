#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include "User.h"
#include <QString>

enum class LoginResult {
    TrivialLogin,
    AdminLogin,
    UserDNE,
    WrongPwd
};

class LoginController
{
public:
    LoginController();
    LoginResult Login(const QString& name, const QString& pwd);
    User* getLoginUserPtr();
private:
    User* current_user;
};

#endif // LOGINCONTROLLER_H
