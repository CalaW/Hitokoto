/**
 * @file EncryptStrategy.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Header of encrypt strategy
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#ifndef ENCRYPTSTRATEGY_H
#define ENCRYPTSTRATEGY_H

#include <string>

using std::string;

/**
 * @class EncryptStrategy
 * @brief abstract base class of method to encrypt string
 * 
 * @interface virtual encrypt()
 * 
 */
class EncryptStrategy {
public:
    virtual string encrypt(const string& src) = 0;
    virtual ~EncryptStrategy();
};


#endif /* ENCRYPTSTRATEGY_H */
