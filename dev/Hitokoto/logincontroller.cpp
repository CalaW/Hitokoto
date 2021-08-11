/**
 * @file logincontroller.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Controller to control login window
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#include "logincontroller.h"
#include <QApplication>

/**
 * @brief Construct a new Login Controller:: Login Controller object
 * 
 * set default path and auto load from file when application is open
 * 
 */
LoginController::LoginController() : m_pCurrentUser(nullptr)
{
}

/**
 * @name Login
 * @brief Login process
 * 
 * @param name 
 * @param pwd 
 * @return LoginResult 
 */
LoginResult LoginController::Login(const QString& name, const QString& pwd) {
    try {
        m_pCurrentUser = User::verify(name.toStdString(), pwd.toStdString());
        if (m_pCurrentUser->isAdmin()) {
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

/**
 * @name getLoginUserPtr
 * @brief get pointer of logined user
 * 
 * @return User* 
 */
User* LoginController::getLoginUserPtr() const {
    return m_pCurrentUser;
}
