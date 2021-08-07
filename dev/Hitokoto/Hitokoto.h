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

enum class Hitokoto_type {
    word,
    action,
    thought
};
ostream& operator<<(ostream& out, const Hitokoto_type type);
istream& operator>>(istream& in, Hitokoto_type& type);

class Hitokoto {
public:
    Hitokoto(const Time& time, const string& content, Hitokoto_type type);
    inline tm& getLocalTime() const {return m_time.getLocalTime();}
    inline tm& getUTCTime() const {return m_time.getUTCTime();}
    inline string getTimeString() const {return m_time.getTimeString(time_format);}
    inline time_t getTime() const {return m_time.getTime();}
    inline const string& getContent() const {return m_content;}
    inline Hitokoto_type getType() const {return m_type;}
    string getTypeString() const;
    inline void setTime(const Time& time) {m_time = time;}
    // inline void setTime(time_t time) {m_time.setTime(time);}
    // inline void setTime(tm& time) {m_time.setTime(time);}
    inline void setContent(const string& content) {m_content = content;}
    inline void setType(Hitokoto_type type) {m_type = type;}
    ~Hitokoto();

    static multimap<time_t, Hitokoto*>::const_iterator cbegin();
    static multimap<time_t, Hitokoto*>::const_iterator cend();
    static multimap<time_t, Hitokoto*>::const_iterator upper_bound(time_t);
    static multimap<time_t, Hitokoto*>::const_iterator lower_bound(time_t);
    static size_t size();
    static void loadFromFile(const string& path = default_path);
    static void saveToFile(const string& path = default_path);
    static void setDefaultPath(const string& path);
private:
    Time m_time;
    string m_content;
    Hitokoto_type m_type;

    static multimap<time_t, Hitokoto*, std::greater<time_t>> hitokoto_map;
//    static multimap<time_t, Hitokoto*> hitokoto_map;
    static string default_path;
    static string time_format;

    friend ostream& operator<<(ostream& out, const Hitokoto& src);

    static class Service {
    public:
        Service();
        ~Service();
    } service;
};

#endif /* HITOKOTO_H */
