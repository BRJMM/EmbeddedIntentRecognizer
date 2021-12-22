#pragma once

#include <string>
#include <vector>
#include <memory>

namespace ConsoleIntentRecognizer {

enum IntentActions { WEATHER, CITY_WEATHER, FACT, UNSUPPORTED };

// TODO(bjmorera): Integrate a third party nlp
class NlpWrapper {
public:
    NlpWrapper();
    ~NlpWrapper();

    IntentActions CategorizeAction(const std::string& input) const;

private:
    bool MatchesKeyWords(const std::vector<std::string>& keyWords,
                         const std::vector<std::string>& itemsToVerify) const;
    bool IsFact(const std::vector<std::string>& items) const;
    bool IsWeather(const std::vector<std::string>& items) const;
    bool IsWeatherCity(const std::vector<std::string>& items) const;
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