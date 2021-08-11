/**
 * @file Cipher.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Implementation of class Cipher.
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#include "Cipher.h"

using std::string;

/**
 * @name makeFromCipher
 * @brief static factory method to make Cipher
 * 
 * @param cipher ciphertext
 * @param strategy ptr to encrypt strategy
 * @return Cipher 
 */
Cipher Cipher::makeFromCipher(const string& cipher, EncryptStrategy* strategy) {
    Cipher temp{};
    temp.m_strCipherText = cipher;
    temp.s_pEncryptStr = strategy;

    return temp;
}

/**
 * @name Cipher
 * @brief Construct a new Cipher object from plaintext
 * 
 * @param plain plaintext 
 * @param init_strategy ptr to encrypt strategy
 */
Cipher::Cipher(const string& plain, EncryptStrategy* init_strategy)
    : s_pEncryptStr(init_strategy) {
    m_strCipherText = s_pEncryptStr->encrypt(plain);
}

/**
 * @brief Copy construct a new Cipher object
 * 
 * @param src 
 */
Cipher::Cipher(const Cipher& src) {
    s_pEncryptStr = src.s_pEncryptStr;
    m_strCipherText = src.m_strCipherText;
}

/**
 * @name Cipher
 * @brief Construct a new Cipher object, does nothing
 * 
 */
Cipher::Cipher() {}

Cipher& Cipher::operator=(const Cipher& src) {
    if (this != &src) {
        m_strCipherText = src.m_strCipherText;
        s_pEncryptStr = src.s_pEncryptStr;
    }
    return *this;
}

/**
 * @brief inequal operator, test if ciphertext is same as plaintext
 * 
 * @param src plaintext
 * @return true 
 * @return false 
 */
bool Cipher::operator!=(const string& src) const {
    return m_strCipherText != s_pEncryptStr->encrypt(src);
}

/**
 * @brief equal operator, test if ciphertext is same as plaintext
 * 
 * @param src plaintext
 * @return true 
 * @return false 
 */
bool Cipher::operator==(const string& src) const {
    return m_strCipherText == s_pEncryptStr->encrypt(src);
}

/**
 * @name update
 * @brief update cipher from plaintext
 * 
 * @param plain plaintext
 */
void Cipher::update(const string& plain) {
    m_strCipherText = s_pEncryptStr->encrypt(plain);
    //TODO permission control
}

/**
 * @brief stream insert operator, output ciphertext
 * 
 * @param out 
 * @param src 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Cipher& src) {
    out << src.m_strCipherText;
    return out;
}

/**
 * @brief stream extraction operator, make from input plaintext
 * 
 * @param in 
 * @param src 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& in, Cipher& src) {
    string temp;
    in >> temp;
    src.update(temp);
    return in;
}