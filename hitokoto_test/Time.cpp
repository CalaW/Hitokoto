//
//  Time.cpp
//  DEMO_DAY_01_TIME
//
//  Created by Jingtao Fan on 2021/7/26.
//

#include "Time.h"
#include <iostream>

bool Time::Is24Format = true;

void Time::Set(unsigned int Hour, unsigned int Minute, unsigned int Second){
    if (Hour < 24 && Minute < 60 && Second < 60) {
        this->m_Hour = Hour;
        this->m_Minute = Minute;
        this->m_Second = Second;
    }
}

Time::Time(unsigned int Hour, unsigned int Minute, unsigned int Second): Hour(m_Hour), Minute(m_Minute), Second(m_Second){
    Set(Hour, Minute, Second);
}