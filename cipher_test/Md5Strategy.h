/**
 * @file Md5Strategy.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Header of Md5 strategy
 * @version 0.1
 * @date 2021-08-07
 * 
 * "Md5.h" is from bzflag (http://www.bzflag.org)
 * 
 */
#ifndef MD5STRATEGY_H
#define MD5STRATEGY_H

#include <string>
#include "EncryptStrategy.h"

using std::string;

/**
 * @class MD5Strategy
 * @brief Strategy to encrypt string to cipher using md5 hash
 * 
 * @interface encrypt()
 * 
 */
class Md5Strategy : public EncryptStrategy {
public:
    //encrypt plaintext to ciphertext
    string encrypt(const string& src) override;
};

#endif /* MD5STRATEGY_H */