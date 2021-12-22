#include <string>
#include <algorithm>

#include "Console.h"
#include "IntentRecognizer.h"

std::string ToLower(const std::string& input){
    std::string copy = input;
    std::for_each(copy.begin(), copy.end(), [](char & c){c = ::tolower(c);});
    return copy;
}

int main(){
    auto exitCondition = false;
    ConsoleIntentRecognizer::IntentRecognizer intentRecognizer;

    while(!exitCondition){
        Utils::Console::Get()->DisplayMessage("Input:");
        const auto userInput = ToLower(Utils::Console::Get()->ReadUserInput());

        if("exit" == userInput) {
            exitCondition = true;
        }
        else if (0 < userInput.length()) {
            const auto result = intentRecognizer.Process(userInput);
            Utils::Console::Get()->DisplayMessage(result);
            Utils::Console::Get()->DisplayBlankLine();
        }
    }
    return 0;
}