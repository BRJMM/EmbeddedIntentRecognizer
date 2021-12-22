cmake_minimum_required(VERSION 3.5)
project(IntentRecognizer)

add_executable(console_application Program.cpp IntentRecognizer.cpp Console.cpp)

target_include_directories(console_application PRIVATE ${CMAKE_SOURCE_DIR}/src)
