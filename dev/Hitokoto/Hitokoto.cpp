#include <fstream>
#include <exception>
#include "Hitokoto.h"

using std::pair;
using std::multimap;
using std::istream;
using std::ostream;

//multimap<time_t, Hitokoto*> Hitokoto::hitokoto_map {};
multimap<time_t, Hitokoto*, std::greater<time_t>> Hitokoto::hitokoto_map {};
string Hitokoto::default_path = "hitokoto.txt";
string Hitokoto::time_format = "%Ex %EX";

Hitokoto::Service Hitokoto::service {};

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

Hitokoto::Hitokoto(const Time& time, const string& content, Hitokoto_type type)
: m_time(time), m_content(content), m_type(type) {
    hitokoto_map.insert({m_time.getTime(), this});
}

Hitokoto::~Hitokoto() {
    auto ret = hitokoto_map.equal_range(m_time.getTime());
    for (auto it = ret.first; it != ret.second ; ++it) {
        if (this == (*it).second) {
            hitokoto_map.erase(it);
            break;
        }
    }
}

string Hitokoto::getTypeString() const {
    switch (m_type) {
    case Hitokoto_type::word:
        return "word";
    case Hitokoto_type::action:
        return "action";
    case Hitokoto_type::thought:
        return "thought";
    }
}

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

void Hitokoto::saveToFile(const string& path) {
    std::ofstream hitokoto_file(path);
    if (!hitokoto_file.is_open()) {
        throw std::invalid_argument("Cannot create file \"" + path + "\"");
    }
    for (const auto& it : hitokoto_map) {
        hitokoto_file << *it.second << std::endl;
    }
}

void Hitokoto::setDefaultPath(const string &path) {
    default_path = path;
}
multimap<time_t, Hitokoto*>::const_iterator Hitokoto::cbegin() {
    return hitokoto_map.cbegin();
}
multimap<time_t, Hitokoto*>::const_iterator Hitokoto::cend() {
    return hitokoto_map.cend();
}
multimap<time_t, Hitokoto*>::const_iterator Hitokoto::upper_bound(time_t time) {
    return hitokoto_map.upper_bound(time);
}

multimap<time_t, Hitokoto*>::const_iterator Hitokoto::lower_bound(time_t time) {
    return hitokoto_map.lower_bound(time);
}

size_t Hitokoto::size() {
    return hitokoto_map.size();
}

ostream& operator<<(ostream& out, const Hitokoto& src) {
    out << src.m_time.getTime() << std::endl << src.m_type
        << std::endl << src.m_content;
    return out;
}

Hitokoto::Service::Service() {
#ifdef AutoLoadHitoList
    Hitokoto::loadFromFile(default_path);
#endif
}

Hitokoto::Service::~Service() {
#ifdef AutoSaveHitoList
    Hitokoto::saveToFile(default_path);
#endif
    for (auto it = hitokoto_map.begin(); it != hitokoto_map.end();) {
        delete (*(it++)).second; //avoid iterator invalidity
    }
}
