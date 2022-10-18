#include <catch2/catch_test_macros.hpp>
#include "../JSONP.h"


TEST_CASE("testing constructor") {
    JSONP test("../testJSON.json");
    test.parse();
    int i = 1;
    REQUIRE(i == 1);
}