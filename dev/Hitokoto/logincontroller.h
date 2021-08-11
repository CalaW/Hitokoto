/**
 * @file logincontroller.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Controller of login window
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
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

/**
 * @class LoginController
 * @brief controller class of login window
 * 
 */
class LoginController
{
public:
    LoginController();
    LoginResult Login(const QString& name, const QString& pwd);
    User* getLoginUserPtr() const;
private:
    User* m_pCurrentUser;
};

#endif // LOGINCONTROLLER_H
