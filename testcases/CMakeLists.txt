CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

PROJECT(Lab2)

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

add_subdirectory(lib/Catch2)
include_directories(${CMAKE_SOURCE_DIR})

ADD_EXECUTABLE(proj1Test
  jsonTC.cpp
  ../JSONP.h ../JSONP.cpp
)

target_link_libraries(proj1Test PRIVATE Catch2::Catch2WithMain)