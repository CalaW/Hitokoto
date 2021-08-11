/**
 * @file MyTime.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Time class
 * @version 0.1
 * @date 2021-08-07
 * 
 * inspired from ctime
 * use time_t (seconds since 1970-1-1 00:00:00 UTC) as data
 * 
 */
#ifndef MYTIME_H
#define MYTIME_H

#include <ctime>
#include <iostream>

using std::ostream;
using std::istream;
using std::string;

/**
 * @class Time
 * @brief time class
 * 
 */
class Time {
public:
    //constructor
    Time();
    Time(time_t time);
    Time(tm& time); //https://www.cplusplus.com/reference/ctime/tm/
    Time(unsigned int year, unsigned int mon, unsigned int mday,
         unsigned int hour, unsigned int min, unsigned int sec);

    //getter
    inline time_t getTime() const {return m_Time;}
    inline tm& getLocalTime() const {return *localtime(&m_Time);}
    inline tm& getUTCTime() const {return *gmtime(&m_Time);}
    string getTimeString(const string& format = s_strDefaultFormat) const;

    //setter
    void setTime(time_t time);
    void setTime(tm& time);
    void setTime(unsigned int year, unsigned int mon, unsigned int mday,
         unsigned int hour, unsigned int min, unsigned int sec);

    //static method
    static Time now();
    static inline bool isLeapYear(const unsigned int year);
    static inline bool isValid(time_t time) {return time >= 0;}
    static bool isValid(tm& time);
    static bool isValid(unsigned int year, unsigned int mon, unsigned int mday,
         unsigned int hour, unsigned int min, unsigned int sec);

    
    //operator
    bool operator> (const Time& aTime) const;
    bool operator< (const Time& aTime) const;
    bool operator>=(const Time& aTime) const;
    bool operator<=(const Time& aTime) const;
    bool operator==(const Time& aTime) const;
    bool operator!=(const Time& aTime) const;
    friend ostream& operator<<(ostream& out, const Time& src);
    friend istream& operator>>(istream& out, Time& src);

private:
    time_t m_Time; //seconds since epoch

    static unsigned int s_uiMaxYear;
    static unsigned int s_uiMinYear;
    static string s_strDefaultFormat; //https://www.cplusplus.com/reference/ctime/strftime/
};

inline bool Time::isLeapYear(const unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

#endif /* MYTIME_H */
