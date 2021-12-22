#pragma once

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

namespace Utils {

class Utils {
public:
    static std::string ToLower(const std::string& input);
    static std::vector<std::string> Split(const std::string& input, char delim = ' ');
    static bool Contains(const std::vector<std::string>& input, const std::string& search);
    static std::string RemoveSpecialCharacters(const std::string& input);
};

inline std::string Utils::ToLower(const std::string& input) {
    std::string copy = input;
    std::for_each(copy.begin(), copy.end(), [](char & c){c = ::tolower(c);});
    return copy;
}

inline std::vector<std::string> Utils::Split(const std::string& input, char delim) {
    std::vector<std::string> output;
    std::stringstream copy(input);
    std::string itemResult;
    while (std::getline(copy, itemResult, delim)) {
        output.push_back(itemResult);
    }
    return output;
}

inline bool Utils::Contains(const std::vector<std::string>& input, const std::string& search)
{
    return std::find(input.begin(), input.end(), search) != input.end();
}

inline std::string Utils::RemoveSpecialCharacters(const std::string& input) {
    auto copy = input;
    const std::vector<char> specialCharacters = {',', '.', '?', ';'};
    for (const auto& character : specialCharacters) {
        copy.erase(std::remove(copy.begin(), copy.end(), character), copy.end());
    }
    return copy;
}

} // namespace Utils