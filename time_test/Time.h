#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <iostream>

using std::ostream;
using std::istream;

class Time {
public:
    Time();
    Time(time_t time);
    Time(tm& time);
    Time(unsigned int year, unsigned int mon, unsigned int mday,
         unsigned int hour, unsigned int min, unsigned int sec);
    inline time_t getTime() const {return m_time;}
    inline tm& getLocalTime() const {return *localtime(&m_time);}
    inline tm& getUTCTime() const {return *gmtime(&m_time);}
    void setTime(time_t time);
    void setTime(tm& time);
    void setTime(unsigned int year, unsigned int mon, unsigned int mday,
         unsigned int hour, unsigned int min, unsigned int sec);

    static Time now();
    static inline bool isLeapYear(const unsigned int year);
    static inline bool isValid(time_t time) {return time >= 0;}
    static bool isValid(tm& time);
    static bool isValid(unsigned int year, unsigned int mon, unsigned int mday,
         unsigned int hour, unsigned int min, unsigned int sec);
    friend ostream& operator<<(ostream& out, const Time& src);
    friend istream& operator>>(istream& out, Time& src);

private:
    time_t m_time;

    static unsigned int max_year;
    static unsigned int min_year;
};

inline bool Time::isLeapYear(const unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

#endif /* TIME_H */
