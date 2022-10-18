#include <catch2/catch_test_macros.hpp>
#include "School.h"
#include <iostream>
using namespace std;


TEST_CASE ("school basic operations") {
    //a school can be constructed
    School school1("a school", "hs", 1000);

    //can get the data members from the school
    REQUIRE(school1.getBudget() == 1000);
    REQUIRE(school1.getName() == "a school");
    REQUIRE(school1.getType() == "hs");

    //budget can be changed
    school1.setBudget(500);
    REQUIRE(school1.getBudget() == 500);

}

TEST_CASE("Distribute basic operations")
{
    // a distribute class can be made
   //Distributor dist;
   //dist.getProduce("../test.json");
}
