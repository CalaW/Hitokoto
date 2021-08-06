#ifndef HITOKOTO_H
#define HITOKOTO_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Time.h"

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
    inline time_t getTime() const {return m_time.getTime();}
    inline const string& getContent() const {return m_content;}
    inline Hitokoto_type getType() const {return m_type;}
    inline void setTime(const Time& time) {m_time = time;}
    // inline void setTime(time_t time) {m_time.setTime(time);}
    // inline void setTime(tm& time) {m_time.setTime(time);}
    inline void setContent(const string& content) {m_content = content;}
    inline void setType(Hitokoto_type type) {m_type = type;}
    ~Hitokoto();

    static void loadFromFile(const string& path);
    static void saveToFile(const string& path);
private:
    Time m_time;
    string m_content;
    Hitokoto_type m_type;

    static multimap<time_t, Hitokoto*> hitokoto_map;

    friend ostream& operator<<(ostream& out, const Hitokoto& src);

    static class Service {
    public:
        Service();
        ~Service();
    } service;
};

#endif /* HITOKOTO_H */