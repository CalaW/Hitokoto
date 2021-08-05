//
//  Time.hpp
//  DEMO_DAY_01_TIME
//
//  Created by Jingtao Fan on 2021/7/26.
//

#ifndef Time_hpp
#define Time_hpp

#include <string>

//v0.4
//typedef struct _Time {
//    unsigned int Hour;
//    unsigned int Minute;
//    unsigned int Second;
//}Time;
//
//bool SetTime(unsigned int h, unsigned int m, unsigned int s, Time* pTime);


//v1.0
class Time {
public:
    //Added from V1.2
    //deleted from V1.3
    //Time();
    //Added from V1.3
    Time(unsigned int Hour = 0, unsigned int Minute = 0, unsigned int Second = 0);
    void Set(unsigned int Hour, unsigned int Minute, unsigned int Second);
    //std::string GetFormatString();
    
    //Added from V1.1
    const unsigned int& Hour;
    const unsigned int& Minute;
    const unsigned int& Second;
    //Added end
    
    static bool Is24Format;
    static bool IsFillByZero;
    
    //deleted from V1.2
    //void Show();
private:
    unsigned int m_Hour;
    unsigned int m_Minute;
    unsigned int m_Second;
};

#endif /* Time_hpp */
