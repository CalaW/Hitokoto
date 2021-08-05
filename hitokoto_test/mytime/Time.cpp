#include <exception>
#include "Time.h"

unsigned int Time::max_year = 3000;
unsigned int Time::min_year = 1970;

Time::Time(time_t time) {
    setTime(time);
}

Time::Time(tm& time) {
    setTime(time);
}

void Time::setTime(time_t time) {
    if (isValid(time)) {
        m_time = time;
    }
}

void Time::setTime(tm& time) {
    if (isValid(time)) {
        m_time = mktime(&time);
    }
}

bool Time::isValid(tm& time) {
    if (time.tm_year < min_year || time.tm_year > max_year) {return false;}
    if (time.tm_mon < 1 || time.tm_mon > 12) {return false;}
    unsigned int day_of_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(time.tm_year)) {day_of_month[2-1]++;} //leap time.tm_year
    if (time.tm_mday < 1 || time.tm_mday > day_of_month[time.tm_mon - 1]) {return false;}
}

bool Time::isValid
(unsigned int year, unsigned int mon, unsigned int mday,
unsigned int hour, unsigned int min, unsigned int sec) {

    
}