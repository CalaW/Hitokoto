/**
 * @file TrivialUser.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#ifndef TRIVIALUSER_H
#define TRIVIALUSER_H

#include <string>
#include "User.h"

using std::string;

/**
 * @class TrivialUser
 * @brief trivial user class
 * 
 */
class TrivialUser : public User {
public:
    bool isAdmin() const override;
private:
    TrivialUser(const string& name, const string& pwd);
    TrivialUser(const string& name, const Cipher& pwd);
    ~TrivialUser() override;

    //friend declaration for permission.
    friend class AdminUser; //admin have full control
    friend void User::loadFromFile(const string&);
    friend void User::addTrivialUser(const string&, const string&);
};

#endif /* TRIVIALUSER_H */
