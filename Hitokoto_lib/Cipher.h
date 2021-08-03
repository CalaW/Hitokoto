#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include "EncryptStrategy.h"

using std::string;

class Cipher {
public:
    Cipher(const string& plain, EncryptStrategy* strategy);
    static Cipher makeFromCipher(const string& cipher, EncryptStrategy* strategy);

    void update(const string& plain);
    bool operator==(const string& src);
    bool operator!=(const string& src);
    friend std::ostream& operator<<(std::ostream& out, const Cipher& src);

private:
    EncryptStrategy* encrypt_strategy;
    string cipher_text;
    Cipher();
};

#endif /* CIPHER_H */
