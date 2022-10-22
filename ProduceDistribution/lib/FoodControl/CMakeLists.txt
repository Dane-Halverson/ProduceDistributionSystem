CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(Produce VERSION 1 LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/lib/Date)

add_library( Produce
ProduceFactory.h ProduceFactory.cpp
ProduceInterface.h ProduceInterface.cpp 
Produce/apple.h 
Produce/carrots.h
Produce/lettuce.h
Produce/onions.h
Produce/squash.h
Produce/tomatoes.h
)

target_link_libraries(Produce PUBLIC Date)
target_include_directories (Produce PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})