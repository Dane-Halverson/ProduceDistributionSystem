
ADD_EXECUTABLE(proj1Test
  jsonTC.cpp
  ../JSONP.h ../JSONP.cpp
)
target_link_libraries(proj1Test PRIVATE Catch2::Catch2WithMain)
