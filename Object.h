//
// Created by smurf on 20.07.22.
//

#ifndef USM_OBJECT_H
#define USM_OBJECT_H
#include <string>

class Object {
    std::string obj_;
    //int type; // 0 is int - i specifier; 1 is string - s specifier
public:
    Object(int object);
    Object(const std::string& object);
    void add_ut_object(const std::string& name);
    void close();
    std::string to_str() const;
};


#endif //USM_OBJECT_H
