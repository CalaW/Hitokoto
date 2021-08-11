/**
 * @file User.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Header file of user
 * 
 * abstract class. derived to AdminUser and TrivialUser
 * 
 * use std::map<usrname, User*> to store user list
 * 
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#ifndef USER_H
#define USER_H

#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <exception>
#include <memory>
#include "EncryptStrategy.h"
#include "Md5Strategy.h"
#include "Cipher.h"

#undef AutoLoadUsrList
#define AutoSaveUsrList

using std::string;
using std::map;
using std::ostream;

/**
 * @class User
 * @brief User class
 * 
 */
class User {
public: 
    //static method
    static User* verify(const string& name, const string& pwd); //verify user existance
    static void loadFromFile(const string& path = s_strDefaultPath);
    static void saveToFile(const string& path = s_strDefaultPath);
    static void setDefaultPath(const string& path);

    inline const string& getName() const {return m_strName;}
    void changePwd(const string& plain);

    //method to verify admin permission
    virtual bool isAdmin() const = 0;

    //method for admin to manage user
    void addTrivialUser(const string& usrname, const string& pwd);
    void deleteTrivialUser(const string& usrname);

    //destructor
    virtual ~User();

    //stream output operator
    friend ostream& operator<<(ostream& out, const User& src);


protected:
    //protected constructor
    User(const string& usrname, const string& pwd);
    User(const string& usrname, const Cipher& cipher_pwd);

private:
    string m_strName; //username
    Cipher m_CipherPwd; //password

    static map<string, User*> s_UserMap; //static std::map to store user list
    static string s_strDefaultPath; //default path to user file
    static const std::shared_ptr<EncryptStrategy> s_pEncryptStr; //user cipher encrypt strategy

    /**
     * @class Service
     * @brief Service class of User
     * 
     * provide auto File IO and delete function
     * 
     */
    static class Service {
    public:
        Service();
        ~Service();
    } s_Service;
};

#endif /* USER_H */
