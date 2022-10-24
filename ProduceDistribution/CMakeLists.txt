CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

PROJECT(FoodDistribution)

find_package(Doxygen OPTIONAL_COMPONENTS dot)
if (DOXYGEN_FOUND)

  set(DOXYGEN_CALLER_GRAPH YES)
  set(DOXYGEN_CALL_GRAPH YES)
  set(DOXYGEN_EXTRACT_ALL YES)

  doxygen_add_docs(DistributorDocs ${PROJECT_SOURCE_DIR})
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

SET(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

option(MAKE_CATCH2_TESTS "whether or not to compile catch2 tests" OFF)

# build your external frameworks first
#
# Catch2
if (MAKE_CATCH2_TESTS)
  add_subdirectory(lib/Catch2-devel)
endif()
# Json
#
# this project also needs the nlohmann json project.  Best way to include
# it is the following:
# FROM https://github.com/nlohmann/json
# Typically you don't care so much for a third party library's tests to be run from your own project's code.
set(JSON_BuildTests
    OFF
    CACHE INTERNAL "")

# If you only include this third party in PRIVATE source files, you do not need to install it when your main project
# gets installed. set(JSON_Install OFF CACHE INTERNAL "")
#
# Don't use include(nlohmann_json/CMakeLists.txt) since that carries with it unintended consequences that will break the
# build.  It's generally discouraged (although not necessarily well documented as such) to use include(...) for pulling
# in other CMake projects anyways.
add_subdirectory(lib/json-develop)
add_subdirectory(lib/FoodControl)
add_subdirectory(lib/Date)


include_directories(${CMAKE_SOURCE_DIR}/lib/json-develop/include)

include_directories(${CMAKE_SOURCE_DIR}/lib/Date)
#add_subdirectory(testcases)


#if in TestBuild then make unit tests
if (${PROJECT_SOURCE_DIR} EQUAL ${CMAKE_SOURCE_DIR}/TestBuild)
  set(MAKE_CATCH2_TESTS ON)
endif()

#catch2 unit tests
if (MAKE_CATCH2_TESTS)
  ADD_EXECUTABLE(testDate
    UnitTests/testDate.cpp
  )

  ADD_EXECUTABLE (testjson
    UnitTests/testjson.cpp
  )

  ADD_EXECUTABLE (testProduce
    UnitTests/testProduce.cpp 
  )

  ADD_EXECUTABLE ( testBinaryHeap
    UnitTests/testBinaryHeap.cpp
  )

  #ADD_EXECUTABLE (test00
  #UnitTests/test00.cpp 
  #ProduceInterface.h 
  #School.h School.cpp
  #Date.h Date.cpp 
  #DateParser.h DateParser.cpp 
  #Produce/Tomato.h
  #)

  ADD_EXECUTABLE(jsonTest
  UnitTests/jsonTC.cpp
  JSONP.h JSONP.cpp
  JSONPS.h JSONPS.cpp
  )

  ADD_EXECUTABLE(ProduceFactoryTesting
  UnitTests/ProduceFactoryTesting.cpp
  )

  ADD_EXECUTABLE (testDistributor
    UnitTests/testDist.cpp 
    JSONP.h JSONP.cpp 
    JSONPS.h JSONPS.cpp
    Distributor.h Distributor.cpp 
    School.h School.cpp
  )

  #jsonTest
  target_link_libraries(jsonTest PRIVATE Catch2::Catch2WithMain)
  target_link_libraries(jsonTest PRIVATE nlohmann_json::nlohmann_json)

  #testBinaryHeap
  target_link_libraries(testBinaryHeap PRIVATE Catch2::Catch2WithMain)


  #test00
  #target_link_libraries(test00 PRIVATE Catch2::Catch2WithMain)
  #target_link_libraries(test00 PRIVATE nlohmann_json::nlohmann_json)

  #testDate
  target_link_libraries(testDate PRIVATE Catch2::Catch2WithMain)
  target_link_libraries(testDate PUBLIC Date)

  #testjson
  target_link_libraries(testjson PRIVATE nlohmann_json::nlohmann_json)
  target_link_libraries(testjson PRIVATE Catch2::Catch2WithMain)

  #testProduce
  target_link_libraries(testProduce PRIVATE Catch2::Catch2WithMain)
  target_link_libraries(testProduce PUBLIC Produce)
  target_link_libraries(testProduce PUBLIC Date)


  #testFoodfactory
  target_link_libraries(ProduceFactoryTesting PRIVATE Catch2::Catch2WithMain)
  target_link_libraries(ProduceFactoryTesting PUBLIC Produce)
  target_link_libraries(ProduceFactoryTesting PUBLIC Date)

  #testDistributor
  target_link_libraries(testDistributor PRIVATE Catch2::Catch2WithMain)
  target_link_libraries(testDistributor PUBLIC Produce)
  target_link_libraries(testDistributor PUBLIC Date)

endif()

add_library( FoodDistributor
    Distributor.h Distributor.cpp
    JSONP.h JSONP.cpp
    JSONPS.h JSONPS.cpp
    School.h School.cpp
    BinaryHeap.h 
)

target_link_libraries(FoodDistributor PUBLIC Produce)
target_link_libraries(FoodDistributor PUBLIC Date)
target_link_libraries(FoodDistributor PRIVATE nlohmann_json::nlohmann_json)


target_include_directories (FoodDistributor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})