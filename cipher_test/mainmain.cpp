#include <iostream>
#include <string>
#include "Md5.h"

using std::string;

int main()
{
    string plain;
    std::cin >> plain;
    std::cout << MD5(plain).hexdigest() << std::endl;
    return 0;
}