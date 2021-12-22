cmake_minimum_required(VERSION 3.5)
project(IntentRecognizer)

add_executable(IntentRecognizer Program.cpp IntentRecognizer.cpp Console.cpp)

target_include_directories(IntentRecognizer PRIVATE ${CMAKE_SOURCE_DIR}/src)
