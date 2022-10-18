CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

PROJECT(betterOrg)

find_package(Doxygen OPTIONAL_COMPONENTS dot)
if (DOXYGEN_FOUND)

  set(DOXYGEN_CALLER_GRAPH YES)
  set(DOXYGEN_CALL_GRAPH YES)
  set(DOXYGEN_EXTRACT_ALL YES)

  doxygen_add_docs(docs ${PROJECT_SOURCE_DIR})
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

SET(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

# build your external frameworks first
#
# Catch2
add_subdirectory(lib/Catch2)

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

include_directories(${CMAKE_SOURCE_DIR}/lib/json-develop/include)
add_subdirectory(testcases)

