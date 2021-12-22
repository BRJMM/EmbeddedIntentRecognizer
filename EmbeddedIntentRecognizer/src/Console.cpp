
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

void Console::DisplayMessage(const std::string& message) {
    printf("%s\n", message.c_str());
}

std::string Console::ReadUserInput() {
    std::string userInput;
    std::getline(std::cin, userInput);
    return userInput;
}

void Console::ClearConsole() {
    printf("\033c");
}