/**
 * @file Cipher.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Header of class Cipher
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */

#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include "EncryptStrategy.h"

using std::string;

class Cipher {
public:
    //constructor
    Cipher(const string& plain, EncryptStrategy* strategy);
    //copy constructor
    Cipher(const Cipher& src);

    //static factory method
    static Cipher makeFromCipher(const string& cipher, EncryptStrategy* strategy);

    //copy assignment operator
    Cipher& operator=(const Cipher& src);
    //update cipher from plaintext
    void update(const string& plain);
    //equal operator, test if ciphertext is equal to plaintext
    bool operator==(const string& src) const;
    //inequal operator, test if ciphertext is equal to plaintext
    bool operator!=(const string& src) const;
    //stream instert operator, output ciphertext
    friend std::ostream& operator<<(std::ostream& out, const Cipher& src);
    //stream extraction operator, make from input plaintext
    friend std::istream& operator>>(std::istream& in, Cipher& src);

private:
    EncryptStrategy* s_pEncryptStr; //store encrypt strategy
    string m_strCipherText; //store ciphertext
    //a default constructor, does nothing
    Cipher();
};

#endif /* CIPHER_H */
