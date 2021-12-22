#pragma once

#include <iostream>
#include <string>

namespace Utils {

class Console {
public:
    static Console* Get();
    ~Console();

    void DisplayMessage(const std::string& message) const;
    void DisplayBlankLine() const;
    std::string ReadUserInput() const;
    void ClearConsole() const;

private:
    Console() {}

    static Console* consoleSingleton;
};

} // namespace Utilss