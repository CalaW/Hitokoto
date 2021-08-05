#include <iostream>
#include <ctime>
#include "Hitokoto.h"

using std::cin;
using std::cout;

int main()
{
    time_t timeT;
    tm* timeS;
    time(&timeT);
    std::cout << timeT << std::endl;
    timeS = localtime(&timeT);
    std::cout << "Local: " << asctime(timeS) << std::endl;
    timeS = gmtime(&timeT);
    std::cout << "UTC:   " << asctime(timeS) << std::endl;

    cin >> timeS->tm_year >> timeS->tm_mon >> timeS->tm_mday
        >> timeS->tm_hour >> timeS->tm_min >> timeS->tm_sec;
    timeS->tm_year -= 1900;
    timeS->tm_mon -= 1;

    std::cout << mktime(timeS) << std::endl;
    std::cout << timeS->tm_year << timeS->tm_mon << timeS->tm_mday
        << timeS->tm_hour << timeS->tm_min << timeS->tm_sec << timeS->tm_isdst << std::endl;
    std::cout << asctime(timeS) << std::endl;

    // Hitokoto::loadFromFile("hitokoto.txt");

    // tm timeS = {0};
    // time_t timeV;
    // Hitokoto_type type;
    // cin >> timeS.tm_year >> timeS.tm_mon >> timeS.tm_mday
    //     >> timeS.tm_hour >> timeS.tm_min >> timeS.tm_sec
    //     >> type;
    // new Hitokoto(timeS, "Hello world", type);
    // time(&timeV);
    // new Hitokoto(*localtime(&timeV), "currenttime", Hitokoto_type::thought);
    // while (true) {
    //     string operation;
    //     cin >> operation;
    //     if (operation == "add") {
    //     }
    //     Hitokoto::saveToFile("operation.txt");
    // }

    // Hitokoto::saveToFile("hitokoto.txt");
    return 0;
}