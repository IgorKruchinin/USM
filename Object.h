//
// Created by smurf on 20.07.22.
//

#ifndef USM_OBJECT_H
#define USM_OBJECT_H
#include <string>
#include <typeinfo>
#include <type_traits>


class Object {
    int ivalue_;
    std::string svalue_;
    short type_; // 0 is int - i specifier; 1 is string - s specifier
    std::string ut_object_;

public:
    Object(int object);
    Object(const std::string& object);
    void add_ut_object(const std::string& name);
    //template <typename VAL>
    short get_type();
    int get_ivalue();
    std::string get_svalue();
};

/*template <typename VAL>
VAL get_value(Object object) {
    std::string value;
    int i = 3;
    if (object.obj_.size() >= 4) {
        while (object.obj_[i] != '<' && object.obj_[i + 1] != 'e' && object.obj_[i + 2] != '>') {
            value += object.obj_[i];
        }
    }
    if (object.obj_[1] == 'i') {
        return std::stoi(value);
    } else {
        return value;
    }
}*/


#endif //USM_OBJECT_H
