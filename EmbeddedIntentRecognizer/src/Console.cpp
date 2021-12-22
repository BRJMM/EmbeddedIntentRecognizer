
#include "Console.h"

using namespace Utils;

Console* Console::consoleSingleton = 0;

Console* Console::Get() {
    if(consoleSingleton == 0){
        consoleSingleton = new Console();
    }

    return consoleSingleton;
}

Console::~Console() = default;

void Console::DisplayMessage(const std::string& message) const {
    printf("\033[3;47;35m%s\033[0m\n", message.c_str());
}

void Console::DisplayBlankLine() const {
    printf("\n");
}

std::string Console::ReadUserInput() const {
    std::string userInput;
    std::getline(std::cin, userInput);
    return userInput;
}

void Console::ClearConsole() const {
    printf("\033c");
}