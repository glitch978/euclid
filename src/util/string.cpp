#include "util/string.hpp"
#include "util/types.h"

std::vector<std::string> util::ssplit(std::string s, std::string delimeter) {
    std::vector<std::string> tokens;
    std::string token;
    u64 pos;

    while ((pos = s.find(delimeter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimeter.length());
    }
    tokens.push_back(s);
    
    return tokens;
}

const char* util::to_cstr(std::string s) {
    static thread_local std::string sloc;
    sloc = std::move(s);
    return sloc.c_str();
}

