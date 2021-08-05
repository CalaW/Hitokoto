/**
 * @file Date.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Header of Date
 * @version 0.1
 * @date 2021-07-26
 * 
 * 
 */

#ifndef DATE_H
#define DATE_H

#include <string>
#include <exception>

/**
 * @brief Date class
 * 
 */
class Date {
public:
    const unsigned int& year; //const reference
    const unsigned int& month;
    const unsigned int& date;

    static const unsigned int& default_year;
    static const unsigned int& default_month;
    static const unsigned int& default_date;

    Date(); //default constructor
    Date(unsigned int year, unsigned int month, unsigned int date); //constructor
    Date(const Date& src); //copy constructor
    Date& operator=(const Date& src); //copy assignment operator
    void SetDate(const unsigned int year, const unsigned int month,
                const unsigned int date); //setter
    ~Date() = default; //default destructor

    static void ChangeYearRange(const unsigned int min, const unsigned int max);
    static void ChangeDefaultDate(const unsigned int year, const unsigned int month,
                                  const unsigned int date);
    static bool isValid(const unsigned int year, const unsigned int month,
                            const unsigned int date); //verify date validity
    bool isValid();
    inline static bool isLeapYear(const unsigned int year); //verify leap year

    /**
     * @brief Exception class for Date object
     * 
     */
    class Date_exception : public std::exception {
    public:
        inline bool HasOccur() {return !msg_list.empty();}
        inline void Add(std::string msg) {msg_list.append(msg);}
        const char* what() const noexcept override {return msg_list.c_str();}
    private:
        std::string msg_list;
    };

private:
    static unsigned int min_year; //year range
    static unsigned int max_year;
    static unsigned int _default_year;
    static unsigned int _default_month;
    static unsigned int _default_date;

    unsigned int _year; //data
    unsigned int _month;
    unsigned int _date;
};

inline bool Date::isLeapYear(const unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
#endif
