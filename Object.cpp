//
// Created by smurf on 20.07.22.
//

#include "Object.h"


Object::Object(int object) {
    obj_ =  "<i>" + std::to_string(object);
}
Object::Object(const std::string& object) {
    obj_ = "<s>" + object;
}
void Object::add_ut_object(const std::string& name) {
    obj_ += "<p>" + name + "</p>";
}
void Object::close() {
    obj_ += "</e>";
}
std::string Object::to_str() const {
    return obj_;
}