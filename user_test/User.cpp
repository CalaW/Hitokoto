#include <memory>
#include <exception>
#include "EncryptStrategy.h"
#include "User.h"

using std::pair;
using std::map;
using std::string;
using std::ostream;

map<string, User*> User::user_map{};

const std::shared_ptr<EncryptStrategy> User::encrypt_strategy (new Md5Strategy());

User* User::verify(const string& name, const string& pwd) {
    auto it = user_map.find(name);
    if (it == user_map.end()) {
        throw std::invalid_argument("User does not exist!");
    } else if (it->second->cipher_pwd != pwd) {
        throw std::invalid_argument("Wrong user name or password!");
    }
    return it->second;
}

User::User(const string& usrname, const string& pwd)
: name(usrname), cipher_pwd(pwd, encrypt_strategy.get()) {
    auto result = user_map.insert({usrname, this});
    if(!result.second) {
        // if (usrname == "Admin") {
        //     throw std::invalid_argument("Only one admin user is allowed!");
        // }
        throw std::invalid_argument("Duplicate user name!");
    }
}

void User::loadFromFile(const string& path) {}
void User::saveToFile(const string& path) {}

void User::changePwd(const string& plain) {
    cipher_pwd.update(plain);
}

ostream& operator<<(ostream& out, const User& src) {
    out << src.name << "\n" << src.cipher_pwd;
    return out;
}