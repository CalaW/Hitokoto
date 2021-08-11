#ifndef HITOKOTO_H
#define HITOKOTO_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <functional>
#include "MyTime.h"

#undef AutoLoadHitoList
#define AutoSaveHitoList

using std::string;
using std::multimap;
using std::shared_ptr;
using std::ostream;
using std::istream;

/**
 * @enum Hitokoto_type
 * @brief define type of hitokoto
 * 
 */
enum class Hitokoto_type {
    word,
    action,
    thought
};
//IO for Hitokoto_type
ostream& operator<<(ostream& out, const Hitokoto_type type);
istream& operator>>(istream& in, Hitokoto_type& type);

class Hitokoto {
public:
    //constructor
    Hitokoto(const Time& time, const string& content, Hitokoto_type type);

    //cannot copy
    Hitokoto(const Hitokoto&) = delete;
    Hitokoto& operator=(const Hitokoto&) = delete;

    //getter
    inline tm& getLocalTime() const;
    inline tm& getUTCTime() const;
    inline string getTimeString() const;
    inline time_t getTime() const;
    inline const string& getContent() const;
    inline Hitokoto_type getType() const;
    string getTypeString() const;

    //setter
    inline void setTime(const Time& time);
    inline void setContent(const string& content);
    inline void setType(Hitokoto_type type);

    //destructor
    ~Hitokoto();

    //static method related to multimap
    static multimap<time_t, Hitokoto*>::const_iterator getConstBegin();
    static multimap<time_t, Hitokoto*>::const_iterator getConstEnd();
    static multimap<time_t, Hitokoto*>::const_iterator getUpperBound(time_t);
    static multimap<time_t, Hitokoto*>::const_iterator getLowerBound(time_t);
    static size_t size();

    //static method related to file IO    
    static void loadFromFile(const string& path = s_strDefaultPath);
    static void saveToFile(const string& path = s_strDefaultPath);
    static void setDefaultPath(const string& path);

private:
    //publish time
    Time m_Time;
    //content
    string m_strContent;
    //type
    Hitokoto_type m_Type;

    //Container to store all hitokoto message, using std::multimap
    static multimap<time_t, Hitokoto*, std::greater<time_t>> s_HitokotoMap;
    //Path to default file path
    static string s_strDefaultPath;
    //Default time format for output
    static string s_strTimeFormat;

    //operator<< to output
    friend ostream& operator<<(ostream& out, const Hitokoto& src);

    /**
     * @class Service
     * @brief Service class of hitokoto, provide auto file IO and delete function
     * 
     */
    static class Service {
    public:
        Service();
        ~Service();
    } s_Service;
};

/**
 * @brief get local time
 * 
 * @return tm& 
 */
tm& Hitokoto::getLocalTime() const {
    return m_Time.getLocalTime();
}

/**
 * @brief get utc time
 * 
 * @return tm& 
 */
tm& Hitokoto::getUTCTime() const {
    return m_Time.getUTCTime();
}

/**
 * @brief get string of publish time
 * 
 * @return string 
 */
string Hitokoto::getTimeString() const {
    return m_Time.getTimeString(s_strTimeFormat);
}

/**
 * @brief get seconds since epoch
 * 
 * @return time_t 
 */
time_t Hitokoto::getTime() const {
    return m_Time.getTime();
}

/**
 * @brief get content
 * 
 * @return const string& 
 */
const string& Hitokoto::getContent() const {
    return m_strContent;
}

/**
 * @brief get type
 * 
 * @return Hitokoto_type 
 */
Hitokoto_type Hitokoto::getType() const {
    return m_Type;
}

/**
 * @brief set publish time
 * 
 * @param time 
 */
void Hitokoto::setTime(const Time& time) {
    m_Time = time;
}

/**
 * @brief set content
 * 
 * @param content 
 */
void Hitokoto::setContent(const string& content) {
    m_strContent = content;
}

/**
 * @brief set type
 * 
 * @param type 
 */
void Hitokoto::setType(Hitokoto_type type) {
    m_Type = type;
}
#endif /* HITOKOTO_H */
