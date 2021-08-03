#include "Cipher.h"

using std::string;

Cipher Cipher::makeFromCipher(const string& cipher, EncryptStrategy* strategy) {
    Cipher temp{};
    temp.cipher_text = cipher;
    temp.encrypt_strategy = strategy;

    return temp;
}

Cipher::Cipher(const string& plain, EncryptStrategy* init_strategy)
    : encrypt_strategy(init_strategy) {
    cipher_text = encrypt_strategy->encrypt(plain);
}

Cipher::Cipher() {}

bool Cipher::operator!=(const string& src) {
    return cipher_text != encrypt_strategy->encrypt(src);
}

bool Cipher::operator==(const string& src) {
    return cipher_text == encrypt_strategy->encrypt(src);
}

void Cipher::update(const string& plain) {
    cipher_text = encrypt_strategy->encrypt(plain);
    //TODO permission control
}

std::ostream& operator<<(std::ostream& out, const Cipher& src) {
    out << src.cipher_text;
    return out;
}