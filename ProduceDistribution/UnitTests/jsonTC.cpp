#include <catch2/catch_test_macros.hpp>
#include "../JSONP.h"
#include "../JSONPS.h"
#include <iostream>


TEST_CASE("JSONP basic operations") {
    JSONP test("testJSONP.json");
    std::cout << "made test\n";
    JSONPS testSchool("testJSONS.json");
    std::cout << "made testSchool\n";
    REQUIRE(test.getDate() == "Sept 18 2021");
    std::cout << test.getDate() << "\n";
    REQUIRE(test.produceHasDateOfPick(0) == false);
    REQUIRE(test.getProduceCount() == 3);
    REQUIRE(test.getDaysSincePicked() == 1);
    REQUIRE(test.getProduceWeight(2) == 45);
    REQUIRE(test.getProduceType(0) == "tomatoes");
    REQUIRE(test.getCPP(2) == 0.5);
    REQUIRE(test.produceHasDateOfPick(1));
    REQUIRE(test.getProduceDateOfPick(1) == "Jan 5 2022");

    REQUIRE(testSchool.getSchoolCount() == 5);
    REQUIRE(testSchool.getSchool(1) == "Lincoln Park Middle School");
    REQUIRE(testSchool.getSchoolBudget(2) == 320.00);
    REQUIRE(testSchool.getSchoolType(3) == "hs"); 
}

TEST_CASE("") {

}