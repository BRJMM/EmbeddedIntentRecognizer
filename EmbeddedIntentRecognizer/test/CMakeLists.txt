cmake_minimum_required(VERSION 3.5)
project(IntentRecognizer)

add_executable(IntentRecognizerUnitTest IntentRecognizerUnitTest.cpp ${CMAKE_SOURCE_DIR}/src/IntentRecognizer.cpp)

target_compile_options(IntentRecognizerUnitTest PRIVATE -Wall -Wextra)

target_include_directories(IntentRecognizerUnitTest PRIVATE ${CMAKE_SOURCE_DIR}/src)
