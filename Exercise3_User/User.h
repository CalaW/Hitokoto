/**
 * @file User.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-28
 * 
 * 
 */

#ifndef USER_H
#define USER_H

#include <vector>
#include <string>
#include <algorithm>
#include <exception>

using std::string;
using std::vector;

enum userType {
    Trivial, /**< Trivial 0 */
    Admin    /**< Admin   1 */
};

/**
 * @brief Class for user object
 * 
 * Consists of two type of users, admin and trivial user, only one admin
 * user exists at the same time.
 * 
 */
class User {
public:
    User() = delete; //can't construct user without name and pwd
    User(const User&) = delete; //can't copy user
    User& operator=(const User&) = delete; //can't copy user

    static bool AddAdminUser(); //method for add Admin
    static bool AddTrivialUser(const string& name, const string& pwd);

private:
    string _name; //user name
    string _pwd;  //user password
    userType _type;

    static vector<User*> user_index; //vector to index all user
    static string admin_name; //default admin username
    static string admin_pwd; //default admin password
    //static bool _admin_exist; //flag to show existence of admin user

    User(const string& name, const string& pwd, userType type); //constructor
    static void ClearAllUser(); //method to delete all user

    /**
     * @brief Class for destruct all user when program exits.
     * 
     */
    class Garbo {
    private:
        inline ~Garbo() {User::ClearAllUser();}
    };
    static Garbo garbo; //static garbo object

    /**
     * @brief Exception class for User object
     * 
     */
    class UserException : public std::exception {
    public:
        inline UserException(string msg) : _msg(msg) {}
        const char* what() const noexcept override {return _msg.c_str();}
    private:
        string _msg;
    };
};

class Test : protected User {
    using User::User;

};
#endif
