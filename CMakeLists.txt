cmake_minimum_required(VERSION 3.22)

project(FoodDist VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#
# Use Doxygen to make the documentation for the code
#
find_package(Doxygen OPTIONAL_COMPONENTS dot mscgen dia)
if (DOXYGEN_FOUND)

  set(DOXYGEN_CALLER_GRAPH YES)
  set(DOXYGEN_CALL_GRAPH YES)
  set(DOXYGEN_EXTRACT_ALL YES)

  doxygen_add_docs(foodDistDocs ${PROJECT_SOURCE_DIR})
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

#
# Enable Clang-Tidy use for Static Analysis
#
option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" OFF)

if(ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
    set(CLANG_TIDY_COMMAND "${CLANGTIDY}" "-checks=*,-fuchsia-*,-google-*,-zircon-*,-abseil-*,-modernize-use-trailing-return-type,-llvm*")
    message("Found clang tidy: ${CLANGTIDY}")
  else()
    message(SEND_ERROR "clang-tidy could not be located.")
  endif()
endif()

option(ENABLE_CPPCHECK "Enable static analysis with cppcheck" OFF)
if(ENABLE_CPPCHECK)
  find_program(CPPCHECK cppcheck)
  if(CPPCHECK)
    set(CMAKE_CXX_CPPCHECK ${CPPCHECK} --suppress=missingInclude --enable=all)
  else()
    message(SEND_ERROR "cppcheck enable but not installed or not found.")
  endif()
endif()

if (MSVC)
  # MSVC uses a different warning system
  add_compile_options(/W4 /WX)
else()
  # Both, GCC and Clang support the same option set
  # add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# --------------------------------------------------------------------
# OpenGL Related Components needed for imGUI
# --------------------------------------------------------------------
find_package(OpenGL REQUIRED)
link_libraries (${OPENGL_LIBRARY})

# To be able to include the GLFW header from your code, you need to tell the compiler where to find it.
add_subdirectory(${CMAKE_SOURCE_DIR}/glfw-master)

# Once GLFW has been added to the project, the GLFW_LIBRARIES cache variable contains all link-time dependencies of GLFW
# as it is currently configured. To link against GLFW, link against them and the glfw target.
include_directories(${CMAKE_SOURCE_DIR}/glfw-master/include)
message(STATUS "${GLFW_LIBRARIES}")
set(GLFW_STATIC_LIBRARIES "${GLFW_LIBRARIES}")

# ##################################################################
# Food Dist Executable
# ##################################################################

# imgui source is within the imgui/ folder so make
# sure we add that as one of the include directories
include_directories(${CMAKE_SOURCE_DIR}/imgui)
add_subdirectory(${CMAKE_SOURCE_DIR}/ProduceDistribution)
include_directories(${CMAKE_SOURCE_DIR}/ProduceDistribution)


add_executable( foodDist
 foodDist.cpp
 FoodDistAdapter.h 

 FoodDist_DataSource.h 
 FoodDist_GUI.cpp FoodDist_GUI.h

 imgui/imgui.cpp imgui/imgui.h imgui/imconfig.h
 imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp
 imgui/imgui_impl_glfw.cpp imgui/imgui_impl_glfw.h imgui/imgui_impl_opengl3.cpp imgui/imgui_impl_opengl3.h
)
target_link_libraries (foodDist PUBLIC FoodDistributor)

target_link_libraries (foodDist ${GLEW_LIBRARIES})
#target_link_libraries (foodDist glfw ${GLFW_STATIC_LIBRARIES})

