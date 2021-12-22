#include <string>

#include "Utils.h"
#include "Console.h"
#include "IntentRecognizer.h"

int main(){
    auto exitCondition = false;
    ConsoleIntentRecognizer::IntentRecognizer intentRecognizer;

    while(!exitCondition){
        Utils::Console::Get()->DisplayMessage("Input:");
        const auto userInput = Utils::Utils::ToLower(Utils::Console::Get()->ReadUserInput());

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