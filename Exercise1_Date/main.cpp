/**
 * @file main.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Test for Date
 * @version 0.1
 * @date 2021-07-27
 * 
 * 
 */
#include "Date.h"
#include <iostream>

using std::cin, std::cout, std::endl;
int main()
{
    Date date1;
    cout << "Default date: " << date1.year << "-"
        << date1.month << "-" << date1.date << endl;

    Date date3 = date1;
    cout << "Copy Constructor: " << date3.year << "-"
        << date3.month << "-" << date3.date << endl;

    unsigned int year;
    unsigned int month;
    unsigned int date;
    unsigned int max, min;
    int status;

    while (std::cin >> status) {
        try
        {
            switch(status) {
            case 1:
                cin >> year >> month >> date;
                Date::ChangeDefaultDate(year, month, date);
                break;
            case 2:
                cin >> min >> max;
                Date::ChangeYearRange(min, max);
                break;
            case 0:
                cin >> year >> month >> date;
                Date date2(year, month, date);
                cout << "Success: " << date2.year << "-" << date2.month << "-" 
                    << date2.date <<endl<<endl;
                break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    cout << "Invalid Input. Program abort." << endl;

    return 0;
}