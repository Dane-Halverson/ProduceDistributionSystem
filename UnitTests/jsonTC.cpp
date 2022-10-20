#include <catch2/catch_test_macros.hpp>
#include "../JSONP.h"
#include <iostream>


TEST_CASE("JSONP basic operations") {
    JSONP test("../testJSONP.json", "../testJSONS.json");
    REQUIRE(test.getDate() == "Sept 18 2021");
    REQUIRE(test.produceHasDateOfPick(0) == false);
    REQUIRE(test.getProduceCount() == 3);
    REQUIRE(test.getDaysSincePicked() == 1);
    REQUIRE(test.getProduceWeight(2) == 45);
    REQUIRE(test.getProduceType(0) == "tomatoes");
    REQUIRE(test.getCPP(2) == 0.5);
}