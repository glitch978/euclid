#pragma once

#include <vector>
#include <string>

namespace util {
    std::vector<std::string> ssplit(std::string string, std::string delimeter);

    const char* to_cstr(std::string s);
}
