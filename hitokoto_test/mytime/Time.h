//
//  Time.hpp
//  DEMO_DAY_04_USER_XCODE
//
//  Created by Jingtao Fan on 2021/8/5.
//

#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time{
public:
    Time();
    Time(unsigned int Hour, unsigned int Minute, unsigned int Second);
    Time(const Time& aTime);
    Time& operator=(const Time& aTime);
    ~Time();
    void setTime(unsigned int Hour, unsigned int Minute, unsigned int Second);
    // void SetHour(unsigned int Hour);
    // void SetMinute(unsigned int Minute);
    // void SetSecond(unsigned int Second);
    //return the Seconds'count from 00:00:00, 00:00:00 is the first(1, not 0) second
    // unsigned int InSeconds() const;
    // bool operator> (const Time& aTime) const;
    // bool operator< (const Time& aTime) const;
    // bool operator>=(const Time& aTime) const;
    // bool operator<=(const Time& aTime) const;
    // bool operator==(const Time& aTime) const;
    // bool operator!=(const Time& aTime) const;
    // Time& operator++();
    // Time  operator++(int);
    // Time& operator--();
    // Time  operator--(int);
    //return days'count between two time, 00:00:01-00:00:00 is 1, 00:00:00-00:00:01 is -1,
    // long long operator-(const Time& aTime) const;
    // friend ostream& operator<<(ostream& Stream, const Time& aTime);
    // friend istream& operator>>(istream& Stream, Time& aTime);
    static Time now();
    static inline bool isValid
        (unsigned int Hour, unsigned int Minute, unsigned int Second);
    const unsigned int& Hour;
    const unsigned int& Minute;
    const unsigned int& Second;
private:
    unsigned int m_Hour;
    unsigned int m_Minute;
    unsigned int m_Second;
};

inline bool Time::isValid (unsigned int Hour
    , unsigned int Minute, unsigned int Second) {
    return Hour < 24 && Minute < 60 && Second < 60;
}

#endif /* TIME_H */
