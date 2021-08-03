#include <memory>
#include "EncryptStrategy.h"
#include "User.h"

const std::shared_ptr<EncryptStrategy> encrypt_strategy(new Md5Strategy());


bool User::verify(const string& name, const string& pwd) {
    return user_map[name]->cipher_pwd == pwd;
}

void User::loadFromFile(const string& path) {}
void User::saveToFile(const string& path) {}

const string& User::getName() {
    return name;
}

void User::changePwd(const string& plain) {
    cipher_pwd.update(plain);
}

ostream& operator<<(ostream& out, const User& src) {
    out << src.name << "\n" << src.cipher_pwd;
}