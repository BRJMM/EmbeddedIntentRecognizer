#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <IntentRecognizer.h>

TEST_CASE("Intent Executor returns actions", "[Intent-Executor]" ) {
    ConsoleIntentRecognizer::IntentExecutor intentExecutor;

    SECTION("Weather") {
        REQUIRE("Intent: Get Weather" == intentExecutor.Execute(ConsoleIntentRecognizer::WEATHER));
    }

    SECTION("Weather City") {
        REQUIRE("Intent: Get Weather City" == intentExecutor.Execute(ConsoleIntentRecognizer::CITY_WEATHER));
    }

    SECTION("Fact") {
        REQUIRE("Intent: Get Fact" == intentExecutor.Execute(ConsoleIntentRecognizer::FACT));
    }

    SECTION("Unsupported") {
        REQUIRE("Intent: Unsupported" == intentExecutor.Execute(ConsoleIntentRecognizer::UNSUPPORTED));
    }
}

TEST_CASE("NLP Wrapper categorizes actions", "[NLP-Wrapper]" ) {
    ConsoleIntentRecognizer::NlpWrapper nlpWrapper;

    SECTION("Weather") {
        REQUIRE(ConsoleIntentRecognizer::UNSUPPORTED == nlpWrapper.CategorizeAction("What is the weather like today?"));
    }

    SECTION("Weather City") {
        REQUIRE(ConsoleIntentRecognizer::UNSUPPORTED == nlpWrapper.CategorizeAction("What is the weather like in Paris today?"));
    }

    SECTION("Fact") {
        REQUIRE(ConsoleIntentRecognizer::UNSUPPORTED == nlpWrapper.CategorizeAction("Tell me an interesting fact."));
    }
}
