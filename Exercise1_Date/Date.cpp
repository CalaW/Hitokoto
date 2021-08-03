/**
 * @file Date.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Implementation of Date.h
 * @version 0.1
 * @date 2021-07-26
 * 
 * 
 */

#include "Date.h"
#include <iostream>

unsigned int Date::min_year = 1900;
unsigned int Date::max_year = 9999;
unsigned int Date::_default_year = 1900;
unsigned int Date::_default_month = 1;
unsigned int Date::_default_date = 1;
const unsigned int& Date::default_year = Date::_default_year;
const unsigned int& Date::default_month = Date::_default_month;
const unsigned int& Date::default_date = Date::_default_date;

/**
 * @brief Change year range
 * 
 * @param min minimum year
 * @param max maximum year
 * @exception Dexcept Negative interval
 * @exception Dexcept Default year out of range
 */
void Date::ChangeYearRange(const unsigned int min, const unsigned int max) {
    Date_exception Dexcept;
    if (0 > min || min > max) {
        Dexcept.Add("error: Lower limit is greater than upper limit.\n");
    }
    if (Date::default_year < min || Date::default_year > max) {
        Dexcept.Add("error: Default year out of range.\n");
    }
    if (Dexcept.HasOccur()) {
        throw Dexcept;
    } else {
        Date::min_year = min;
        Date::max_year = max;
    }
}

/**
 * @brief Change default date for default constructor
 * 
 * @param year year
 * @param month month
 * @param date date
 */
void Date::ChangeDefaultDate(const unsigned int year, const unsigned int month,
                        const unsigned int date) {                                    
    if (Date::IsValidDate(year, month, date)) {
        Date::_default_year = year;
        Date::_default_month = month;
        Date::_default_date = date;
    }
}

/**
 * @brief Verify date validity
 * 
 * @exception Dexcept y/m/d out of range
 */
bool Date::IsValidDate(const unsigned int year, const unsigned int month,
                        const unsigned int date) {
    Date_exception Dexcept;
    if (year < min_year || year > max_year) {
        Dexcept.Add("error: Year out of range.\n");
    }
    if (month < 1 || month > 12) {
        Dexcept.Add("error: Month out of range.\n");
    }
    unsigned int day_of_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (IsLeapYear(year)) {day_of_month[2-1]++;}//leap year
    if (month < 1 || month > 12) {
        //jmp
    }
    else if (date < 1 || date > day_of_month[month - 1]) {
        Dexcept.Add("error: Date out of range.\n");
    }
    if (Dexcept.HasOccur()) {
        throw Dexcept;
    } else {
        return true;
    }
}

/**
 * @brief Verify date validity
 * 
 * @retval true: Valid date
 * @retval false: Invalid date
 */
bool Date::IsValidDate() {
    if (year < min_year || year > max_year) {return false;}
    if (month < 1 || month > 12) {return false;}
    unsigned int day_of_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (IsLeapYear(year)) {day_of_month[2-1]++;} //leap year
    if (date < 1 || date > day_of_month[month - 1]) {return false;}
    
    return true;
}

/**
 * @brief Judge leap year
 * 
 * @param year year
 * @retval true: Is leap year 
 * @retval false: Isn't leap year
 */
inline bool Date::IsLeapYear(const unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Default constructor of Date object
 * 
 * @details Using three default value shall cause ambiguity in certain scenario.
 */
Date::Date() : Date(default_year, default_month, default_date) {}

/**
 * @brief Construct a new Date object
 * 
 * @param year year
 * @param month month
 * @param date date
 */
Date::Date(unsigned int year, unsigned int month, unsigned int date) : 
        year(_year), month(_month), date(_date) {
    SetDate(year, month, date);
}

/**
 * @brief Copy constructor
 * 
 * @param src Source Date object
 */
Date::Date(const Date& src) : year(_year), month(_month), date(_date) {
    _year = src._year;
    _month = src._month;
    _date = src._date;
}

/**
 * @brief Copy assignment operator
 * 
 * @param src 
 * @return Date& 
 */
Date& Date::operator=(const Date& src) {
    if (this != &src) {
        _year = src._year;
        _month = src._month;
        _date = src._date;
    }
    return *this;
}

/**
 * @brief Set the Date object
 * 
 * @param set_year 
 * @param set_month 
 * @param set_date 
 */
void Date::SetDate(const unsigned int set_year,
                  const unsigned int set_month,
                  const unsigned int set_date) {
    if (IsValidDate(set_year, set_month, set_date)) {
        _year = set_year;
        _month = set_month;
        _date = set_date;
    }
}
