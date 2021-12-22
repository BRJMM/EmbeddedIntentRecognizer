#include "IntentRecognizer.h"

using namespace ConsoleIntentRecognizer;

NlpWrapper::NlpWrapper() = default;

NlpWrapper::~NlpWrapper() = default;

IntentActions NlpWrapper::CategorizeAction(const std::string& /*input*/) const {
    return UNSUPPORTED;
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
