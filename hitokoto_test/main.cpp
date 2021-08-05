#include <iostream>
#include <ctime>
#include "Hitokoto.h"

using std::cin;
using std::cout;

int main()
{
    // time_t timeT;
    // tm* timeS;
    // time(&timeT);
    // std::cout << timeT << std::endl;
    // timeS = localtime(&timeT);
    // std::cout << "Local: " << asctime(timeS) << std::endl;
    // timeS = gmtime(&timeT);
    // std::cout << "UTC:   " << asctime(timeS) << std::endl;

    Hitokoto::loadFromFile("hitokoto.txt");

    tm m_time = {0};
    time_t timeV;
    Hitokoto_type type;
    cin >> m_time.tm_year >> m_time.tm_mon >> m_time.tm_mday
        >> m_time.tm_hour >> m_time.tm_min >> m_time.tm_sec
        >> type;
    new Hitokoto(m_time, "Hello world", type);
    time(&timeV);
    new Hitokoto(*localtime(&timeV), "currenttime", Hitokoto_type::thought);
    // while (true) {
    //     string operation;
    //     cin >> operation;
    //     if (operation == "add") {
    //     }
    //     Hitokoto::saveToFile("operation.txt");
    // }

    Hitokoto::saveToFile("hitokoto.txt");
    return 0;
}