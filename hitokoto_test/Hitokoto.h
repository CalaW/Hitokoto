#ifndef HITOKOTO_H
#define HITOKOTO_H

#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <memory>

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
    Hitokoto(time_t time, const string& content, Hitokoto_type type);
    Hitokoto(tm& time, const string& content, Hitokoto_type type);
    inline tm& getLocalTime() const {return *localtime(&m_time);}
    inline tm& getUTCTime() const {return *gmtime(&m_time);}
    inline time_t getTime() const {return m_time;}
    inline const string& getContent() const {return m_content;}
    inline Hitokoto_type getType() const {return m_type;}
    inline void setTime(time_t time) {m_time = time;}
    inline void setTime(tm& time) {m_time = mktime(&time);}
    inline void setContent(const string& content) {m_content = content;}
    inline void setType(Hitokoto_type type) {m_type = type;}
    ~Hitokoto();

    static void loadFromFile(const string& path);
    static void saveToFile(const string& path);
private:
    time_t m_time;
    string m_content;
    Hitokoto_type m_type;

    static multimap<time_t, shared_ptr<Hitokoto>> hitokoto_map;

    friend ostream& operator<<(ostream& out, const Hitokoto& src);
};

#endif /* HITOKOTO_H */