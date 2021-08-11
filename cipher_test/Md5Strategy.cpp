/**
 * @file Md5Strategy.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Implementation of md5 encrypt strategy.
 * @version 0.1
 * @date 2021-08-07
 * 
 * "Md5.h" is from bzflag (http://www.bzflag.org)
 * 
 */
#include <string>
#include "Md5Strategy.h"
#include "Md5.h"

using std::string;

/**
 * @name encrypt
 * @brief encrypt plaintext using md5 algorithm
 * 
 * @param src plaintext
 * @return string 
 */
string Md5Strategy::encrypt(const string& src) {
    return MD5(src).hexdigest();
}

/**
 * @name ~Md5Strategy
 * @brief Destroy the Md5Strategy object, do nothing
 * 
 */
Md5Strategy::~Md5Strategy() {}