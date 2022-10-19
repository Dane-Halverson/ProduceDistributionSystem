#include <catch2/catch_test_macros.hpp>
#include "../JSONP.h"


TEST_CASE("testing constructor") {
    JSONP test("../testJSONP.json", "../testJSONS.json");
    REQUIRE(test.getDate() == "Sept 18 2021");
}