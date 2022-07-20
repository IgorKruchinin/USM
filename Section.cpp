//
// Created by smurf on 20.07.22.
//

#include "Section.h"

Section::Section(const std::string& name)
        : name_(name) {}

void Section::add(const std::string& object) {
    objects_.emplace_back(object);
}

void Section::add(int object) {
    Object obj(object);
    objects_.emplace_back(object);
}

Section::operator std::string() const {
    std::string line;
    for (const auto& ob: objects_) {
        line += ob.to_str();
    }
    return line;
}