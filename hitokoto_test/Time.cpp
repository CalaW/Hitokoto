//
//  Time.cpp
//  DEMO_DAY_01_TIME
//
//  Created by Jingtao Fan on 2021/7/26.
//

#include "Time.hpp"
#include <iostream>

bool Time::Is24Format = true;
bool Time::IsFillByZero = true;

//v0.4
///bool SetTime(unsigned int h, unsigned int m, unsigned int s, Time* pTime){
//    if (h < 24 && m < 60 && s < 60) {
//        pTime->Hour = h;
//        pTime->Minute = m;
//        pTime->Second = s;
//        return true;
//    }
//    return false;
//}

//V1.0
void Time::Set(unsigned int Hour, unsigned int Minute, unsigned int Second){
    if (Hour < 24 && Minute < 60 && Second < 60) {
        this->m_Hour = Hour;
        this->m_Minute = Minute;
        this->m_Second = Second;
    }
}

//void Time::Show(){
//    std::cout << this->m_Hour << " : "
//              << this->m_Minute << " : "
//    << this->m_Second << std::endl;
//}

//Added from V1.1
//deleted form V1.3
//Time::Time() : Hour(m_Hour), Minute(m_Minute), Second(m_Second){
//    m_Hour = 1;
//    m_Minute = 1;
//    m_Second = 1;
//}

Time::Time(unsigned int Hour, unsigned int Minute, unsigned int Second): Hour(m_Hour), Minute(m_Minute), Second(m_Second){
    Set(Hour, Minute, Second);
}
//
//std::string Time::GetFormatString() {
//
//}
