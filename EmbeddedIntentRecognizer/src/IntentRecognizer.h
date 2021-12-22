#pragma once

#include <string>

namespace ConsoleIntentRecognizer {

class IntentRecognizer {
public:
    IntentRecognizer();
    ~IntentRecognizer();

    std::string Process(const std::string& input);
};

} // namespace ConsoleIntentRecognizer