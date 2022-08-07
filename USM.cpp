//
// Created by smurf on 19.07.22.
//
// Universal Storage Manager version 0.1
#include <fstream>
#include <string>
#include <map>
#include <vector>


#include "macro_config.h"
#include "Object.h"
#include "Section.h"

#include <iostream>

#define USMVer() USM_VERSION

class ProfileStorage {
    std::string name_;
    std::map<std::string, IntSection> isecs_;
    std::map<std::string, StringSection> ssecs_;
    //std::string text_buf_;
public:
    ProfileStorage(const std::string &name)
        : name_(name) {
        //file_.open("profiles/" + name_, std::fstream::in | std::fstream::out | std::fstream::app);
        system((std::string(MAKEDIR) + " profiles/res/" + name_).c_str());
        /*std::string buf;
        std::cout << file_.is_open();
        if (file_.is_open()) {
            std::cout << '1';
            while (std::getline(file_, buf)) {
                std::cout << buf << '|';
                std::string sec_name;
                std::string object;
                std::vector<Object> objects;
                bool first_in = true;
                bool first_out = true;
                bool continue_reading = false;
                bool is_int = false;
                bool is_str = false;
                bool delim_opened = false;
                bool object_opened = true;
                bool name_entered = false;
                for (const auto &s: buf) {
                    std::cout << s;
                    if (s == '<' && first_in)
                        first_in = false;
                    else if (!first_in && !name_entered && s != '>') {
                        sec_name += s;
                        std::cout << sec_name;
                    } else if (s == '>' && !first_in && !name_entered) {
                        name_entered = true;
                        continue_reading = true;
                        continue;
                    }
                    if (continue_reading) {
                        if (s == '<') {
                            delim_opened = true;
                            continue;
                        }
                        if (delim_opened) {
                            if (s == 'i')
                                is_int = true;
                            else if (s == 's')
                                is_str = true;
                            else if (s == '>')
                                delim_opened = false;
                            else if (s == 'e') {
                                object_opened = false;
                                if (is_int)
                                    objects.emplace_back(object);
                                else if (is_str)
                                    objects.emplace_back(object);
                            }
                        } else if (!delim_opened && (is_str || is_int))
                            object_opened = true;
                        else if (object_opened && s != '<' && !delim_opened)
                            object += s;
                    } else if (first_in && s != '<')
                        throw "SyntaxError";
                }
                sections_.emplace(sec_name, Section(objects));
                //file_.seekg();
                //file_.clear();
                //file_.seekg(0);
            }
        } else {
            throw "Cannot open file";
        }*/
    }


    void to_file() {
        if (IN_TEXT_MODE) {
            std::string text_buf;
            for (auto &s: isecs_) {
                text_buf += "i<" + s.first + ">";
                for (auto &obj: s.second.get_objects()) {
                    text_buf += std::to_string(obj) + "<\\e>";
                }
                text_buf += "\n";
            }
            for (auto &s: ssecs_) {
                text_buf += "s<" + s.first + ">";
                for (auto &obj: s.second.get_objects()) {
                    text_buf += obj + "<\\e>";
                }
            }
            std::ofstream file("profiles/" + name_ + ".uto");
            file << text_buf;
        }
    }

    IntSection &geti (const std::string& name) {
        return isecs_.at(name);
    }

    StringSection &gets (const std::string& name) {
        return ssecs_.at(name);
    }


    void create_isec(const std::string &sec_name) {
        isecs_.emplace(sec_name, IntSection(sec_name));
    }

    void create_ssec(const std::string &sec_name) {
        ssecs_.emplace(sec_name, StringSection(sec_name));
    }
};


