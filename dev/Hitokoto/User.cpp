/**
 * @file User.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Implementation of User class
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#include <memory>
#include <exception>
#include <fstream>
#include "EncryptStrategy.h"
#include "Md5Strategy.h"
#include "User.h"
#include "AdminUser.h"
#include "TrivialUser.h"

using std::pair;
using std::map;
using std::string;
using std::ostream;

//static member initialization
map<string, User*> User::s_UserMap{};
string User::s_strDefaultPath = "user.txt";
const std::shared_ptr<EncryptStrategy> User::s_pEncryptStr(new Md5Strategy());

User::Service User::s_Service {};


/**
 * @brief verify user validity
 * 
 * @param name 
 * @param pwd 
 * @return User* 
 */
User* User::verify(const string& name, const string& pwd) {
    auto it = s_UserMap.find(name);
    if (it == s_UserMap.end()) {
        throw std::invalid_argument("User does not exist!");
    } else if (it->second->m_CipherPwd != pwd) {
        throw std::invalid_argument("Wrong user name or password!");
    }
    return it->second;
}

/**
 * @brief Construct a new User:: User object using plaintext
 * 
 * insert to map
 * 
 * @param usrname 
 * @param pwd 
 */
User::User(const string& usrname, const string& pwd)
: m_strName(usrname), m_CipherPwd(pwd, s_pEncryptStr.get()) {
    if (usrname.empty() || pwd.empty()) {
        throw std::invalid_argument("Cannot use empty user name or password!");
    }
    auto result = s_UserMap.insert({usrname, this});
    if(!result.second) {
        throw std::invalid_argument("Duplicate user name!");
    }
}

/**
 * @brief Construct a new User:: User object using cipher
 * 
 * insert to map
 * 
 * @param usrname 
 * @param pwd 
 */
User::User(const string& usrname, const Cipher& pwd)
: m_strName(usrname), m_CipherPwd(pwd) {
    if (usrname.empty()) {
        throw std::invalid_argument("Cannot use empty user name");
    }
    auto result = s_UserMap.insert({usrname, this});
    if(!result.second) {
        throw std::invalid_argument("Duplicate user name!");
    }
}

/**
 * @brief Destroy the User:: User object
 * 
 * erase from map
 * 
 */
User::~User() {
    s_UserMap.erase(m_strName);
}

/**
 * @brief load user map from file
 * 
 * @param path 
 */
void User::loadFromFile(const string& path) {
    std::ifstream user_file(path);
    if (!user_file.is_open()) {
        throw std::invalid_argument("Cannot open file \"" + path + "\"");
    }
    while (user_file.peek() != EOF) {
        string name;
        string pwd;
        // user_file >> name >> pwd;
        std::getline(user_file, name);
        std::getline(user_file, pwd);
        if (name == "Admin") {
            AdminUser::addAdminUser(Cipher::makeFromCipher(pwd, s_pEncryptStr.get()));
        } else {
            new TrivialUser(name, Cipher::makeFromCipher(pwd, s_pEncryptStr.get()));
        }
    }
    if (s_UserMap.empty() || s_UserMap.count("Admin") == 0) {
        AdminUser::addAdminUser();
    }
}

/**
 * @brief save user map to file
 * 
 * @param path 
 */
void User::saveToFile(const string& path) {
    std::ofstream user_file(path);
    if (!user_file.is_open()) {
        throw std::invalid_argument("Cannot create file \"" + path + "\"");
    }
    for (const auto& it : s_UserMap) {
        user_file << *it.second;
    }
}

/**
 * @brief set default path to user file
 * 
 * @param path 
 */
void User::setDefaultPath(const string &path) {
    s_strDefaultPath = path;
}

/**
 * @brief change password from plaintext
 * 
 * @param plain plaintext
 */
void User::changePwd(const string& plain) {
    m_CipherPwd.update(plain);
}

/**
 * @brief add trivial user
 * 
 * @param usrname 
 * @param pwd 
 */
void User::addTrivialUser(const string& usrname, const string& pwd) {
    if (this->isAdmin()) { //must called by an admin user
        new TrivialUser(usrname, pwd);
    } else {
        throw std::invalid_argument("Permission denied!");
    }
}

/**
 * @brief delete trivial user
 * 
 * @param usrname 
 */
void User::deleteTrivialUser(const string& usrname) {
    if (this->isAdmin()) {
        auto it = s_UserMap.find(usrname);
        if (it == s_UserMap.end()) {
            throw std::invalid_argument("User \"" + usrname + "\" does not exist");
        } else {
            delete (*it).second;
        }
    } else {
        throw std::invalid_argument("Permission denied!");
    }
}

/**
 * @brief operator output stream
 * 
 * @param out 
 * @param src 
 * @return ostream& 
 */
ostream& operator<<(ostream& out, const User& src) {
    out << src.m_strName << "\n" << src.m_CipherPwd << std::endl;
    return out;
}

/**
 * @brief Construct a new User:: Service:: Service object
 * 
 * auto load user map from file when application starts
 * 
 */
User::Service::Service() {
#ifdef AutoLoadUsrList
    User::loadFromFile(default_path);
#endif
}

/**
 * @brief Destroy the User:: Service:: Service object
 * 
 * auto save user map to file when application quit
 * auto delete allocated ptr when app quit
 * 
 */
User::Service::~Service() {
#ifdef AutoSaveUsrList
    User::saveToFile(s_strDefaultPath);
#endif
    for (auto it = s_UserMap.begin(); it != s_UserMap.end();) {
        delete (*(it++)).second;
    }
}
