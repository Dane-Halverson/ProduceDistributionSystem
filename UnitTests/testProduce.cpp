#include <catch2/catch_test_macros.hpp>
#include "ProduceInterface.h"
#include "Produce/Tomato.h"

TEST_CASE("produce basic operations")
{
    // tomato can be constructed
    Tomato tom1(20, "Oct 20 2022", 2, "a farm", 2);
    Tomato tom2(20, "Oct 19 2022", 2, "a differnt farm", 2);
    Tomato tom3(20, "Oct 06 2022", 2, "farm 3", 2);
    // tomato has the correct Weight
    REQUIRE(tom1.getWeight() == 20);
    //tomato Weight can change
    tom1.setWeight(10);
    REQUIRE(tom1.getWeight() == 10);
    //Experation works correctly
    REQUIRE(tom3.getExperInt() < tom2.getExperInt());
    REQUIRE(tom1.getExperInt() > tom2.getExperInt());
}
