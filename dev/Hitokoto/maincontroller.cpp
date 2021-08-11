/**
 * @file maincontroller.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief controller of main window
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#include "maincontroller.h"
#include "Hitokoto.h"
#include <QApplication>
#include <QMessageBox>

/**
 * @brief Construct a new Main Controller:: Main Controller object
 * 
 * auto load hitokoto and user from file
 * 
 */
MainController::MainController() : m_pCurrentUser(nullptr)
{
    Hitokoto::setDefaultPath(QApplication::applicationDirPath().toStdString() + "/../Resources/hitokoto.txt");
    Hitokoto::loadFromFile();
    User::setDefaultPath(QApplication::applicationDirPath().toStdString() + "/../Resources/user.txt");
    User::loadFromFile();
}

/**
 * @name getUserName()
 * @brief get user name from current user
 * 
 * @return QString Username
 */
QString MainController::getUserName() {
    if (m_pCurrentUser == nullptr) {
        return "unlogined user";
    } else {
        return QString::fromStdString(m_pCurrentUser->getName());
    }
}

/**
 * @name setUserPtr
 * @brief set user pointer
 * 
 * @param user 
 */
void MainController::setUserPtr(User* user) {
    m_pCurrentUser = user;
}

/**
 * @name isLogined
 * @brief is user logined?
 * 
 * @return true 
 * @return false 
 */
bool MainController::isLogined() const {
    return m_pCurrentUser != nullptr;
}

/**
 * @name isAdminLogined
 * @brief is admin logined?
 * 
 * @return true 
 * @return false 
 */
bool MainController::isAdminLogined() const {
    return isLogined() && m_pCurrentUser->isAdmin();
}

/**
 * @name addUser
 * @brief method to add an trivial user
 * 
 * @param name 
 * @param pwd 
 * @return true success
 * @return false failed
 */
bool MainController::addUser(const QString &name, const QString &pwd) {
    try {
        m_pCurrentUser->addTrivialUser(name.toStdString(), pwd.toStdString());
        return true;
    } catch (std::exception e) {
        return false;
    }
}

/**
 * @name deleteUser
 * @brief method to delete an trivial user
 * 
 * @param name 
 * @return true success
 * @return false failed
 */
bool MainController::deleteUser(const QString &name) {
    try {
        m_pCurrentUser->deleteTrivialUser(name.toStdString());
        return true;
    }  catch (std::exception e) {
        return false;
    }
}

/**
 * @name adChangeUserPwd
 * @brief method for admin to change trivial user password
 * 
 * @param name 
 * @param pwd 
 * @return true success
 * @return false failed
 */
bool MainController::adChangeUserPwd(const QString &name, const QString &pwd) {
    try {
        m_pCurrentUser->deleteTrivialUser(name.toStdString());
        m_pCurrentUser->addTrivialUser(name.toStdString(), pwd.toStdString());
        return true;
    } catch (std::exception e) {
        return false;
    }
}

/**
 * @name changePwd
 * @brief method to change current user's password
 * 
 * @param prevPwd 
 * @param newPwd 
 * @return true success
 * @return false failed
 */
bool MainController::changePwd(const QString &prevPwd, const QString &newPwd) {
    try {
        if (User::verify(m_pCurrentUser->getName(), prevPwd.toStdString()) == m_pCurrentUser) {
            m_pCurrentUser->changePwd(newPwd.toStdString());
            return true;
        } else {
            return false;
        }
    }
    catch (std::exception e) {
        return false;
    }
}
