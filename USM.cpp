//
// Created by smurf on 19.07.22.
//
// Universal Storage Manager version 0.1
#include <fstream>
#include <string>
#include <map>
#include <vector>
//#include <typeinfo>

#include "macro_config.h"
#include "Object.h"
#include "Section.h"

class ProfileStorage {
    std::string name_;
    std::fstream file_;
    std::map<std::string, Section> sections;
public:
    ProfileStorage(const std::string &name)
        : name_(name) {
        file_.open("profiles/" + name_, std::fstream::in | std::fstream::out);
        file_ << "s<profile>" + name_ + "\n";
        system((std::string(MAKEDIR) + " profiles/res/" + name_).c_str());
    }

    ~ProfileStorage() {
        file_.close();
    }

    Section &operator[] (const std::string& name) {
        return sections.at(name);
    }

    void create_section(const std::string &sec_name) {
        file_ << "s<" + sec_name + "> ";
        sections.emplace(sec_name, Section(sec_name));
    }
};