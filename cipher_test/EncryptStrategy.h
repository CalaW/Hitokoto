#include <string>

#ifndef ENCRYPTSTRATEGY_H
#define ENCRYPTSTRATEGY_H

using std::string;

class EncryptStrategy {
public:
    // virtual string&& encrypt(const string& src) = 0;
    virtual string encrypt(const string& src) = 0;
};

class Md5Strategy : public EncryptStrategy {
public:
    // string&& encrypt(const string& src) override;
    string encrypt(const string& src) override;
};

#endif /* ENCRYPTSTRATEGY_H */