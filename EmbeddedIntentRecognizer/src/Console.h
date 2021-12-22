#pragma once

#include <iostream>
#include <string>

namespace Utils {

class Console {
public:
    static Console* Get();
    ~Console();

    void DisplayMessage(const std::string& message);
    std::string ReadUserInput();
    void ClearConsole();

private:
    Console() {}

    static Console* consoleSingleton;
};

} // namespace Utilss