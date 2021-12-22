#pragma once

#include <string>
#include <memory>

namespace ConsoleIntentRecognizer {

enum IntentActions { WEATHER, CITY_WEATHER, FACT, UNSUPPORTED };

class NlpWrapper {
public:
    NlpWrapper();
    ~NlpWrapper();

    IntentActions CategorizeAction(const std::string& input) const;
};

class IntentExecutor {
public:
    IntentExecutor();
    ~IntentExecutor();

    std::string Execute(const IntentActions& action) const;
};

class IntentRecognizer {
public:
    IntentRecognizer();
    ~IntentRecognizer();

    std::string Process(const std::string& input);

private:
    std::unique_ptr<IntentExecutor> intentExecutor;
    std::unique_ptr<NlpWrapper> nlpWrapper;
};

} // namespace ConsoleIntentRecognizer