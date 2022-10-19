#include <catch2/catch_test_macros.hpp>
#include "../JSONP.h"
#include <iostream>


TEST_CASE("JSONP basic operations") {
    JSONP test("../testJSONP.json", "../testJSONS.json");
    REQUIRE(test.getDate() == "Sept 18 2021");
    REQUIRE(test.produceHasDate(0) == false);


}