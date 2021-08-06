#ifndef USER_H
#define USER_H

#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <exception>
#include <memory>
#include "EncryptStrategy.h"
#include "Cipher.h"

using std::string;
using std::map;
using std::ostream;

class User {
public:
    static User* verify(const string& name, const string& pwd);
    static void loadFromFile(const string& path);
    static void saveToFile(const string& path);

    inline const string& getName() const {return name;}
    virtual bool isAdmin() const = 0;
    void changePwd(const string& plain);
    void addTrivialUser(const string& usrname, const string& pwd);
    void deleteTrivialUser(const string& usrname);
    virtual ~User();
    friend ostream& operator<<(ostream& out, const User& src);

    static const std::shared_ptr<EncryptStrategy> encrypt_str;

protected:
    User(const string& usrname, const string& pwd);
    User(const string& usrname, const Cipher& cipher_pwd);
private:
    string name;
    Cipher cipher_pwd;
    static map<string, User*> user_map;
    static string default_path;
    static class Service {
    public:
        Service();
        ~Service();
    } service;

    friend class AdminUser;
};

#endif /* USER_H */