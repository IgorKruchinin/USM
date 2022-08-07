//
// Created by smurf on 20.07.22.
//

#ifndef USM_USMPARSER_H
#define USM_USMPARSER_H
#include <string>


class USMParser {
    std::string parse_str_
public:
    USMParser(const std::string& parse_str)
        :parse_str_(parse_str)
    {}
    int find(const std::string& substring) {
        return parse_str_.find(substring);
    }
};


#endif //USM_USMPARSER_H
