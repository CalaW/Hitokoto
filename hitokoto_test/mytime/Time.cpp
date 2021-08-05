#include "Time.h"
#include <ctime>

void Time::setTime(unsigned int Hour, unsigned int Minute, unsigned int Second) {
    if (isValid(Hour, Minute, Second)) {
        m_Hour = Hour;
        m_Minute = Minute;
        m_Second = Second;
    }
}

Time::Time(unsigned int Hour, unsigned int Minute, unsigned int Second)
: Hour(m_Hour), Minute(m_Minute), Second(m_Second) {
    setTime(Hour, Minute, Second);
}

Time::Time()
: Hour(m_Hour), Minute(m_Minute), Second(m_Second) {
    setTime(0, 0, 0);
}

Time::Time(const Time& src)
: Hour(m_Hour), Minute(m_Minute), Second(m_Second) {
    setTime(src.Hour, src.Minute, src.Second);
}

Time& Time::operator=(const Time& src) {
    if (this != &src) {
        m_Hour = src.Hour;
        m_Minute = src.Minute;
        m_Second = src.Second;
    }
    return *this;
}

Time::~Time() {}

Time Time::now() {
    time_t time_stamp;
    time(&time_stamp);
    tm* time = localtime(&time_stamp);

    return Time(time->tm_hour, time->tm_min, time->tm_sec);
}