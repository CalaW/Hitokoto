/**
 * @file MyTime.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Time class
 * @version 0.1
 * @date 2021-08-07
 * 
 * inspired by ctime
 * 
 */
#include <exception>
#include <stdexcept>
#include "MyTime.h"

unsigned int Time::s_uiMaxYear = 3000;
unsigned int Time::s_uiMinYear = 1970;
string Time::s_strDefaultFormat = "%Ex %EX"; //https://www.cplusplus.com/reference/ctime/strftime/

/**
 * @brief Construct a new Time:: Time object
 * 
 */
Time::Time() {
    setTime(0);
}

/**
 * @brief Construct a new Time:: Time object from time_t
 * 
 * @param time 
 */
Time::Time(time_t time) {
    setTime(time);
}

/**
 * @brief Construct a new Time:: Time object from tm structure
 * 
 * @param time 
 */
Time::Time(tm& time) {
    setTime(time);
}

/**
 * @brief Construct a new Time:: Time object from ymdhms
 * 
 * @param year 
 * @param mon 
 * @param mday 
 * @param hour 
 * @param min 
 * @param sec 
 */
Time::Time
(unsigned int year, unsigned int mon, unsigned int mday,
unsigned int hour, unsigned int min, unsigned int sec)
{
    setTime(year, mon, mday, hour, min, sec);
}

/**
 * @brief set time from time_t
 * 
 * @param time 
 */
void Time::setTime(time_t time) {
    if (isValid(time)) {
        m_Time = time;
    } else {
        throw std::invalid_argument("time invalid!");
    }
}

/**
 * @brief set time from tm structure
 * 
 * @param time 
 */
void Time::setTime(tm& time) {
    if (isValid(time)) {
        m_Time = mktime(&time);
    } else {
        throw std::invalid_argument("time invalid!");
    }
}

/**
 * @brief set time from ymdhms
 * 
 * @param year 
 * @param mon 
 * @param mday 
 * @param hour 
 * @param min 
 * @param sec 
 */
void Time::setTime(unsigned int year, unsigned int mon, unsigned int mday,
        unsigned int hour, unsigned int min, unsigned int sec) {
    if (isValid(year, mon, mday, hour, min, sec)) {
        tm time = {};
        time.tm_year = year - 1900; //tm year start from 1900
        time.tm_mon = mon - 1;		//tm month start from 0
        time.tm_mday = mday;
        time.tm_hour = hour;
        time.tm_min = min;
        time.tm_sec = sec;
        m_Time = mktime(&time);
    } else {
        throw std::invalid_argument("time invalid!");
    }
}

/**
 * @brief get string of time
 * 
 * @param format 
 * @return string 
 */
string Time::getTimeString(const string &format) const {
    char temp[100] = {0};
    strftime(temp, 100, format.c_str(), localtime(&m_Time));
    return string(temp);
}

/**
 * @brief static method to get current time
 * 
 * @return Time 
 */
Time Time::now() {
    time_t time_stamp;
    time(&time_stamp);

    return Time(time_stamp);
}

/**
 * @brief is time valid from tm structure
 * 
 * @param time 
 * @return true 
 * @return false 
 */
bool Time::isValid(tm& time) {
    return isValid(time.tm_year + 1900, time.tm_mon + 1, time.tm_mday
                    ,time.tm_hour, time.tm_min, time.tm_sec);
}

/**
 * @brief is time valid for from ymdhms
 * 
 * @param year 
 * @param mon 
 * @param mday 
 * @param hour 
 * @param min 
 * @param sec 
 * @return true 
 * @return false 
 */
bool Time::isValid
(unsigned int year, unsigned int mon, unsigned int mday,
unsigned int hour, unsigned int min, unsigned int sec)
{
    if (year < s_uiMinYear || year > s_uiMaxYear) {return false;}
    if (mon < 1 || mon > 12) {return false;}

    unsigned int day_of_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year)) {++day_of_month[2-1];}//leap year

    if (mday < 1 || mday > day_of_month[mon - 1]) { return false;}

    if(hour < 0 || hour > 23 || min < 0 || min > 59 || sec < 0 || sec > 60) {return false;}

    return true;
}


/**
 * @brief compare operator overload
 * 
 */
bool Time::operator>(const Time& aTime) const {
    return m_Time > aTime.m_Time;
}
bool Time::operator<(const Time& aTime) const {
    return m_Time < aTime.m_Time;
}
bool Time::operator>=(const Time& aTime) const {
    return m_Time >= aTime.m_Time;
}
bool Time::operator<=(const Time& aTime) const {
    return m_Time <= aTime.m_Time;
}
bool Time::operator==(const Time& aTime) const {
    return m_Time == aTime.m_Time;
}
bool Time::operator!=(const Time& aTime) const {
    return m_Time != aTime.m_Time;
}

/**
 * @brief stream operator to output time
 * 
 * @param out 
 * @param src 
 * @return ostream& 
 */
ostream& operator<<(ostream& out, const Time& src) {
    out << asctime(localtime(&src.m_Time));
    return out;
}

/**
 * @brief stream operator to input time from tm_t
 * 
 * @param in 
 * @param dst 
 * @return istream& 
 */
istream& operator>>(istream& in, Time& dst) {
    time_t time;
    in >> time;
    dst.setTime(time);
    return in;
}
