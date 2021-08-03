/**
 * @file User.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-28
 * 
 * 
 */

#include "User.h"

//static member initialization
string User::admin_name = "Admin";
string User::admin_pwd = "Admin";
vector<User*> User::user_index{};
//bool User::_admin_exist = false;

/**
 * @brief Method to add an administrator
 * 
 * @retval true: success 
 * @retval false: unsuccess
 */
bool User::AddAdminUser() {
    // if (_admin_exist == false) { //TODO why not?
    //     user_index.push_back(new User(admin_name, admin_pwd, userType::Admin));
    //     return true;
    // }
    // return false;
    bool admin_exist = false;
    std::for_each(user_index.begin(), user_index.end(), [&](User* const iter) {
        if (iter->_type == userType::Admin) {
            admin_exist = true;
        }
    });
    if (admin_exist) {
        return false; //only one admin user can exist
    }
    user_index.push_back(new User(admin_name, admin_pwd, userType::Admin));
    return true;
}

/**
 * @brief Method to add a trivial user
 * 
 * @param name username
 * @param pwd user password
 * @retval true: success
 * @retval false: unsuccess
 */
bool User::AddTrivialUser(const string& name, const string& pwd) {
    if (name == admin_name) {
        return false; //trivial username cannot be admin
    }
    for (const auto& iter : user_index) {
        if (iter->_name == name) {
            return false; //username cannot be same
        }
    }
    user_index.push_back(new User(name, pwd, userType::Trivial));
    return true;
}

/**
 * @brief Method for delete all user
 * 
 */
void User::ClearAllUser() {
    for (auto& iter : user_index) {
        delete iter;
        iter = nullptr; //set pointer to null
    }
}

/**
 * @brief Private constructor of User object
 * 
 * @param name username
 * @param pwd password
 * @param type usertype
 * @exception UserException username/password cannot be empty
 */
User::User(const string& name, const string& pwd, userType type) {
    if (name.empty() || pwd.empty()) {
        throw UserException("error: Username or password cannot be empty.\n");
    }
    _name = name;
    _pwd = pwd;
    _type = type;
}
