#include <catch2/catch_test_macros.hpp>
#include "ProduceInterface.h"
#include <Produce/tomatoes.h>
#include <memory>
using ProPtr = std::shared_ptr<Produce>;

TEST_CASE("produce basic operations")
{
    // tomato can be constructed
    tomatoes tom1(20, "Oct 20 2022", 2, "a farm", 2);
    tomatoes tom2(20, "Oct 19 2022", 2, "a differnt farm", 2);
    tomatoes tom3(20, "Oct 06 2022", 2, "farm 3", 2);
    // tomato has the correct Weight
    REQUIRE(tom1.getWeight() == 20);
    //tomato Weight can change
    tom1.setWeight(10);
    REQUIRE(tom1.getWeight() == 10);
    //Experation works correctly
    REQUIRE(tom3.getExperInt() < tom2.getExperInt());
    REQUIRE(tom1.getExperInt() > tom2.getExperInt());
    
    tomatoes tom4(10, "Sept 18 2021", 1, "farm", 3.4);
    REQUIRE(tom4.getExperString() == "Sep 20 2021");

    ProPtr tomptr = std::make_shared<tomatoes>(10, "Sept 18 2021", 1, "farm", 3.4);
    REQUIRE(tomptr->getExperString() == "Sep 20 2021");
    REQUIRE(tomptr->getType() == "tomatoes");
}
