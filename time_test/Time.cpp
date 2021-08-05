#include <exception>
#include <stdexcept>
#include "Time.h"

unsigned int Time::max_year = 3000;
unsigned int Time::min_year = 1970;

Time::Time() {
    setTime(0);
}

Time::Time(time_t time) {
    setTime(time);
}

Time::Time(tm& time) {
    setTime(time);
}

Time::Time
(unsigned int year, unsigned int mon, unsigned int mday,
unsigned int hour, unsigned int min, unsigned int sec)
{
    setTime(year, mon, mday, hour, min, sec);
}

void Time::setTime(time_t time) {
    if (isValid(time)) {
        m_time = time;
    } else {
        throw std::invalid_argument("time invalid!");
    }
}

void Time::setTime(tm& time) {
    if (isValid(time)) {
        m_time = mktime(&time);
    } else {
        throw std::invalid_argument("time invalid!");
    }
}

void Time::setTime(unsigned int year, unsigned int mon, unsigned int mday,
        unsigned int hour, unsigned int min, unsigned int sec) {
    if (isValid(year, mon, mday, hour, min, sec)) {
        tm time = {0};
        time.tm_year = year - 1900;
        time.tm_mon = mon - 1;
        time.tm_mday = mday;
        time.tm_hour = hour;
        time.tm_min = min;
        time.tm_sec = sec;
        m_time = mktime(&time);
    } else {
        throw std::invalid_argument("time invalid!");
    }
}

Time Time::now() {
    time_t time_stamp;
    time(&time_stamp);

    return Time(time_stamp);
}

bool Time::isValid(tm& time) {
    return isValid(time.tm_year + 1900, time.tm_mon + 1, time.tm_mday
                    ,time.tm_hour, time.tm_min, time.tm_sec);
}

bool Time::isValid
(unsigned int year, unsigned int mon, unsigned int mday,
unsigned int hour, unsigned int min, unsigned int sec)
{
    if (year < min_year || year > max_year) {return false;}
    if (mon < 1 || mon > 12) {return false;}

    unsigned int day_of_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year)) {++day_of_month[2-1];}//leap year

    if (mday < 1 || mday > day_of_month[mon - 1]) { return false;}

    return true;
}

ostream& operator<<(ostream& out, const Time& src) {
    out << asctime(localtime(&src.m_time));
    return out;
}

istream& operator>>(istream& in, Time& dst) {
    time_t time;
    in >> time;
    dst.setTime(time);
    return in;
}