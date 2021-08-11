/**
 * @file Hitokoto.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Header of class Hitokoto, which means "一言"
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#include <fstream>
#include <exception>
#include "Hitokoto.h"

using std::pair;
using std::multimap;
using std::istream;
using std::ostream;


multimap<time_t, Hitokoto*, std::greater<time_t>> Hitokoto::s_HitokotoMap {};
string Hitokoto::s_strDefaultPath = "hitokoto.txt";
string Hitokoto::s_strTimeFormat = "%F %EX"; //use time format based on location

Hitokoto::Service Hitokoto::s_Service {}; //service class init, must init at last

/**
 * @brief stream insertion operator for enum class Hitokoto_type
 * 
 * @param out 
 * @param type 
 * @return ostream& 
 */
ostream& operator<<(ostream& out, const Hitokoto_type type) {
    switch (type) {
    case Hitokoto_type::word:
        out << "word"; break;
    case Hitokoto_type::action:
        out << "action"; break;
    case Hitokoto_type::thought:
        out << "thought"; break;
    }
    return out;
}

/**
 * @brief stream extraction operator for enum class Hitokoto_type
 * 
 * @param in 
 * @param type 
 * @return istream& 
 */
istream& operator>>(istream& in, Hitokoto_type& type) {
    string readin;
    in >> readin;
    // std::getline(in, readin);
    if (readin == "word") {
        type = Hitokoto_type::word;
    } else if (readin == "action") {
        type = Hitokoto_type::action;
    } else if (readin == "thought") {
        type = Hitokoto_type::thought;
    } else {
        throw std::invalid_argument("Hitokoto type " + readin + " did not exist");
    }
    return in;
}

/**
 * @brief Construct a new Hitokoto:: Hitokoto object
 * 
 * add instance to multimap
 * 
 * @param time 
 * @param content 
 * @param type 
 */
Hitokoto::Hitokoto(const Time& time, const string& content, Hitokoto_type type)
: m_Time(time), m_strContent(content), m_Type(type) {
    s_HitokotoMap.insert({m_Time.getTime(), this});
}

/**
 * @brief Destroy the Hitokoto:: Hitokoto object
 * 
 * erase instance from multimap
 * 
 */
Hitokoto::~Hitokoto() {
    auto ret = s_HitokotoMap.equal_range(m_Time.getTime());
    for (auto it = ret.first; it != ret.second ; ++it) {
        if (this == (*it).second) {
            s_HitokotoMap.erase(it);
            break;
        }
    }
}

/**
 * @name getTypeString
 * @brief get type name by string
 * 
 * @return string 
 */
string Hitokoto::getTypeString() const {
    switch (m_Type) {
    case Hitokoto_type::word:
        return "word";
    case Hitokoto_type::action:
        return "action";
    case Hitokoto_type::thought:
        return "thought";
    }
}

/**
 * @name loadFromFile
 * @brief load multimap from file
 * 
 * @param path 
 */
void Hitokoto::loadFromFile(const string& path) {
    std::ifstream hitokoto_file(path);
    if (!hitokoto_file.is_open()) {
        throw std::invalid_argument("Cannot open file \"" + path + "\"");
    }
    while (hitokoto_file.peek() != EOF) {
        Time time;
        string content;
        Hitokoto_type type;
        hitokoto_file >> std::ws >> time;
        hitokoto_file >> std::ws >> type >> std::ws;
        std::getline(hitokoto_file, content);
        new Hitokoto(time, content, type);
    }
}

/**
 * @name saveToFile
 * @brief save multimap to file
 * 
 * @param path 
 */
void Hitokoto::saveToFile(const string& path) {
    std::ofstream hitokoto_file(path);
    if (!hitokoto_file.is_open()) {
        throw std::invalid_argument("Cannot create file \"" + path + "\"");
    }
    for (const auto& it : s_HitokotoMap) {
        hitokoto_file << *it.second << std::endl;
    }
}

/**
 * @name setDefaultPath
 * @brief static method to set default path
 * 
 * @param path 
 */
void Hitokoto::setDefaultPath(const string &path) {
    s_strDefaultPath = path;
}

/**
 * @name getConstBegin
 * @brief static method to get cbegin iterator
 * 
 * @return multimap<time_t, Hitokoto*>::const_iterator 
 */
multimap<time_t, Hitokoto*>::const_iterator Hitokoto::getConstBegin() {
    return s_HitokotoMap.cbegin();
}

/**
 * @name getConstEnd
 * @brief static method to get cend iterator
 * 
 * @return multimap<time_t, Hitokoto*>::const_iterator 
 */
multimap<time_t, Hitokoto*>::const_iterator Hitokoto::getConstEnd() {
    return s_HitokotoMap.cend();
}

/**
 * @name getUpperBound
 * @brief static method to get upper_bound of time
 * 
 * @param time 
 * @return multimap<time_t, Hitokoto*>::const_iterator 
 */
multimap<time_t, Hitokoto*>::const_iterator Hitokoto::getUpperBound(time_t time) {
    return s_HitokotoMap.upper_bound(time);
}

/**
 * @name getLowerBound
 * @brief static method to get lower_bound of time
 * 
 * @param time 
 * @return multimap<time_t, Hitokoto*>::const_iterator 
 */
multimap<time_t, Hitokoto*>::const_iterator Hitokoto::getLowerBound(time_t time) {
    return s_HitokotoMap.lower_bound(time);
}

/**
 * @name size
 * @brief static method to get size of the multimap
 * 
 * @return size_t 
 */
size_t Hitokoto::size() {
    return s_HitokotoMap.size();
}

/**
 * @brief stream operator to output
 * 
 * @param out 
 * @param src 
 * @return ostream& 
 */
ostream& operator<<(ostream& out, const Hitokoto& src) {
    out << src.m_Time.getTime() << std::endl << src.m_Type
        << std::endl << src.m_strContent;
    return out;
}

/**
 * @name Service
 * @brief Construct a new Hitokoto:: Service:: Service object
 * 
 * Autoload hitokoto from file when program started
 * 
 */
Hitokoto::Service::Service() {
#ifdef AutoLoadHitoList
    Hitokoto::loadFromFile(default_path);
#endif
}

/**
 * @brief Destroy the Hitokoto:: Service:: Service object
 * 
 * Autosave hitokoto from file when program exits
 * Auto delete all ptr in multimap when program exits
 * 
 */
Hitokoto::Service::~Service() {
#ifdef AutoSaveHitoList
    Hitokoto::saveToFile(s_strDefaultPath);
#endif
    for (auto it = s_HitokotoMap.begin(); it != s_HitokotoMap.end();) {
        delete (*(it++)).second; //avoid iterator invalidity
    }
}
