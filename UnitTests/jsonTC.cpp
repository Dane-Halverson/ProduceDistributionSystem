#include <catch2/catch_test_macros.hpp>
#include "../JSONP.h"
#include <iostream>


TEST_CASE("JSONP basic operations") {
    JSONP test("../testJSONP.json", "../testJSONS.json");
    REQUIRE(test.getDate() == "Sept 18 2021");
    REQUIRE(test.produceHasExperation(0) == false);
    REQUIRE(test.getProduceCount() == 3);
    REQUIRE(test.getDaysSincePicked() == 1);
    REQUIRE(test.getProduceWeight(2) == 12);
    REQUIRE(test.getProduceType(1) == "tomatoes");
    REQUIRE(test.getCPP(3) == 0.5);
    REQUIRE(test.getProduceExperation(1) == 1);
}