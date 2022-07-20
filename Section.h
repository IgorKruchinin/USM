//
// Created by smurf on 20.07.22.
//

#ifndef USM_SECTION_H
#define USM_SECTION_H
#include "Object.h"
#include <vector>
#include <string>


class Section {
    std::string name_;
    //std::string::iterator it;
    //std::string line;
    std::vector<Object> objects_;
public:
    Section(const std::string& name);
    void add(const std::string& object);
    void add(int object);
    operator std::string() const;
};


#endif //USM_SECTION_H
