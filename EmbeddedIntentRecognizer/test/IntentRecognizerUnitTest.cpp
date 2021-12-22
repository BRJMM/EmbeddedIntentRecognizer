#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <IntentRecognizer.h>
#include <Utils.h>

TEST_CASE("Utils ToLower") {
    SECTION("Empty string case") {
        REQUIRE("" == Utils::Utils::ToLower(""));
    }

    SECTION("Only one letter case") {
        REQUIRE("a" == Utils::Utils::ToLower("A"));
    }

    SECTION("Two letters case") {
        REQUIRE("aa" == Utils::Utils::ToLower("Aa"));
    }

    SECTION("CamelCase case") {
        REQUIRE("camelcase" == Utils::Utils::ToLower("CamelCase"));
    }

    SECTION("snake_case case") {
        REQUIRE("snake_case" == Utils::Utils::ToLower("snake_case"));
    }

    SECTION("More than one word case") {
        REQUIRE("more than one word case" == Utils::Utils::ToLower("More than One Word case"));
    }

    SECTION("Special symbol case") {
        REQUIRE("special symbol case????" == Utils::Utils::ToLower("Special symbol case????"));
    }
}

TEST_CASE("Utils Split") {
    SECTION("Empty string case") {
        REQUIRE(Utils::Utils::Split("").empty());
    }

    SECTION("Only one letter case") {
        const auto result = Utils::Utils::Split("A");
        CHECK(!result.empty());
        REQUIRE(1 == result.size());
        REQUIRE("A" == result.at(0));
    }

    SECTION("Multiple elements case") {
        const auto result = Utils::Utils::Split("A B C");
        CHECK(!result.empty());
        REQUIRE(3 == result.size());
        REQUIRE("A" == result.at(0));
        REQUIRE("B" == result.at(1));
        REQUIRE("C" == result.at(2));
    }

    SECTION("Multiple elements case, semicolon separator") {
        const auto result = Utils::Utils::Split("A;B C", ';');
        CHECK(!result.empty());
        REQUIRE(2 == result.size());
        REQUIRE("A" == result.at(0));
        REQUIRE("B C" == result.at(1));
    }
}

TEST_CASE("Utils Contains") {
    const std::vector<std::string> inputData = {"a", "b"};

    SECTION("Empty vector case") {
        REQUIRE(!Utils::Utils::Contains(std::vector<std::string>(), "st"));
    }

    SECTION("Empty string case") {
        REQUIRE(!Utils::Utils::Contains(inputData, ""));
    }

    SECTION("Return false case") {
        REQUIRE(!Utils::Utils::Contains(inputData, "st"));
    }

    SECTION("Return true case") {
        REQUIRE(Utils::Utils::Contains(inputData, "a"));
    }
}

TEST_CASE("Utils RemoveSpecialCharacters") {
    SECTION("Empty string case") {
        REQUIRE(Utils::Utils::RemoveSpecialCharacters("").empty());
    }

    SECTION("Do not delete any character") {
        REQUIRE("something" == Utils::Utils::RemoveSpecialCharacters("something"));
    }

    SECTION("Delete '.' at the end") {
        REQUIRE("something" == Utils::Utils::RemoveSpecialCharacters("something."));
    }

    SECTION("Delete '.' at the begin") {
        REQUIRE("something" == Utils::Utils::RemoveSpecialCharacters(".something"));
    }

    SECTION("Delete '.' in the middle") {
        REQUIRE("something" == Utils::Utils::RemoveSpecialCharacters("somet.hing"));
    }

    SECTION("Delete '.' on the ends") {
        REQUIRE("something" == Utils::Utils::RemoveSpecialCharacters(".something."));
    }

    SECTION("Delete '.' on the ends and middle") {
        REQUIRE("something" == Utils::Utils::RemoveSpecialCharacters(".somet.hing."));
    }

SECTION("Delete multiple characters") {
        REQUIRE("something" == Utils::Utils::RemoveSpecialCharacters(".somet.h????ing."));
    }
}

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
        REQUIRE(ConsoleIntentRecognizer::WEATHER == nlpWrapper.CategorizeAction("What is the weather like today?"));
    }

    SECTION("Weather City") {
        REQUIRE(ConsoleIntentRecognizer::CITY_WEATHER == nlpWrapper.CategorizeAction("What is the weather like in Paris today?"));
    }

    SECTION("Fact") {
        REQUIRE(ConsoleIntentRecognizer::FACT == nlpWrapper.CategorizeAction("Tell me an interesting fact."));
    }

    SECTION("Unsupported") {
        REQUIRE(ConsoleIntentRecognizer::UNSUPPORTED == nlpWrapper.CategorizeAction("Hello World!!"));
    }
}
