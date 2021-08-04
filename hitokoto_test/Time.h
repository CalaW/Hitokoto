//
//  Time.hpp
//  DEMO_DAY_01_TIME
//
//  Created by Jingtao Fan on 2021/7/26.
//

#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
public:
    Time(unsigned int Hour = 0, unsigned int Minute = 0, unsigned int Second = 0);
    void Set(unsigned int Hour, unsigned int Minute, unsigned int Second);
    const unsigned int& Hour;
    const unsigned int& Minute;
    const unsigned int& Second;
    static bool Is24Format;
    static bool IsFillByZero;
private:
    unsigned int m_Hour;
    unsigned int m_Minute;
    unsigned int m_Second;
};

#endif /* TIME_H */
