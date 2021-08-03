#include <iostream>
#include <string>
#include "Cipher.h"
#include "EncryptStrategy.h"

using std::string;
int main()
{
    string src;
    std::cin >> src;
    Md5Strategy md5_strategy;
    Cipher cipher_text(src, &md5_strategy);
    std::cout << (cipher_text == src) << std::endl;
    std::cout << cipher_text << std::endl << std::endl;
    cipher_text.update("123");
    std::cout << (cipher_text == src) << std::endl;
    std::cout << cipher_text << std::endl;
    return 0;
}