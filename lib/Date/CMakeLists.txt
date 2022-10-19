CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(Date VERSION 1 LANGUAGES CXX)

add_library( Date
Date.h Date.cpp 
DateParser.h DateParser.cpp
)

target_include_directories (Date PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})