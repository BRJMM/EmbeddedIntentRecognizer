#include<algorithm>

#include "IntentRecognizer.h"
#include "Utils.h"

using namespace ConsoleIntentRecognizer;

NlpWrapper::NlpWrapper() = default;

NlpWrapper::~NlpWrapper() = default;

bool NlpWrapper::MatchesKeyWords(const std::vector<std::string>& keyWords,
                                 const std::vector<std::string>& itemsToVerify) const {
    return std::all_of(std::begin(keyWords), std::end(keyWords),
                       [itemsToVerify](const std::string& item){ return Utils::Utils::Contains(itemsToVerify, item); });
}

bool NlpWrapper::IsFact(const std::vector<std::string>& items) const {
    const std::vector<std::string> keyWords = {"fact", "tell"};
    return MatchesKeyWords(keyWords, items);
}

bool NlpWrapper::IsWeather(const std::vector<std::string>& items) const {
    const std::vector<std::string> keyWords = {"weather", "what"};
    return MatchesKeyWords(keyWords, items);
}

bool NlpWrapper::IsWeatherCity(const std::vector<std::string>& items) const {
    const std::vector<std::string> keyWords = {"weather", "what", "in"};
    return MatchesKeyWords(keyWords, items);
}

IntentActions NlpWrapper::CategorizeAction(const std::string& input) const {
    const auto inputItems = Utils::Utils::Split(Utils::Utils::RemoveSpecialCharacters(input));
    std::vector<std::string> inputLowerItems;
    std::transform(inputItems.begin(), inputItems.end(), std::inserter(inputLowerItems, inputLowerItems.begin()),
                   [](const std::string& name) { return Utils::Utils::ToLower(name); });

    IntentActions result;
    if(IsFact(inputLowerItems)){
        result = FACT;
    }
    else if (IsWeatherCity(inputLowerItems)) {
        result = CITY_WEATHER;
    }
    else if (IsWeather(inputLowerItems)) {
        result = WEATHER;
    }
    else {
        result = UNSUPPORTED;
    }

    return result;
}

IntentExecutor::IntentExecutor() = default;

IntentExecutor::~IntentExecutor() = default;

std::string IntentExecutor::Execute(const IntentActions& action) const {
    std::string result;
    switch(action) {
        case WEATHER: {
            result = "Intent: Get Weather";
            break;
        }
        case CITY_WEATHER: {
            result = "Intent: Get Weather City";
            break;
        }
        case FACT: {
            result = "Intent: Get Fact";
            break;
        }
        case UNSUPPORTED:
        default: {
            result = "Intent: Unsupported";
            break;
        }
    }
    return result;
}

IntentRecognizer::IntentRecognizer() : intentExecutor(std::make_unique<IntentExecutor>()),
                                       nlpWrapper(std::make_unique<NlpWrapper>()) {}

IntentRecognizer::~IntentRecognizer() = default;

std::string IntentRecognizer::Process(const std::string& input) {
    const auto actionToExecute = nlpWrapper->CategorizeAction(input);
    return intentExecutor->Execute(actionToExecute);
}
