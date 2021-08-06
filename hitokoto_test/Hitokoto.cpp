#include <fstream>
#include <exception>
#include "Hitokoto.h"

using std::pair;
using std::multimap;
using std::istream;
using std::ostream;

multimap<time_t, shared_ptr<Hitokoto>> Hitokoto::hitokoto_map {};

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
    hitokoto_map.insert({m_time.getTime(), std::shared_ptr<Hitokoto>(this)});
}

Hitokoto::~Hitokoto() {
    auto ret = hitokoto_map.equal_range(m_time.getTime());
    for (auto it = ret.first; it != ret.second ; ++it) {
        if (this == (*it).second.get()) {
            hitokoto_map.erase(it);
            break;
        }
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
        hitokoto_file << *it.second.get() << std::endl;
    }
}

ostream& operator<<(ostream& out, const Hitokoto& src) {
    out << src.m_time.getTime() << std::endl << src.m_type 
        << std::endl << src.m_content;
    return out;
}