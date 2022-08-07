//
// Created by smurf on 20.07.22.
//

#include "Object.h"
#include <type_traits>
#include <typeinfo>

Object::Object(int object) {
    ivalue_ = object;
    type_ = 0;
}
Object::Object(const std::string& object) {
    svalue_ = object;
}
//template <typename VAL>
/*Object::Object(VAL value) {
    if (typeid(value) == typeid(int)) {
        obj_ =  "<i>" + std::to_string(object);
    } else if (typeid(value) == typeid(std::string)) {
        obj_ = "<s>" + object;
    }
    value_ = object;
}*/
void Object::add_ut_object(const std::string& name) {
    ut_object_ = name;
}

/*std::type_info& Object::get_type() {
    if (type_ == 0)
        return typeid(int);
    else
        return typeid(std::string);
}*/

short Object::get_type() {
    return type_;
}

/*template <typename VAL>*/
std::string Object::get_svalue() {
    /*std::string value;
    int i = 3;
    if (obj_.size() >= 4) {
        while (obj_[i] != '<' && obj_[i + 1] != 'e' && obj_[i + 2] != '>') {
            value += obj_[i];
        }
    }*/
    return svalue_;
}

int Object::get_ivalue() {
    return ivalue_;
}
