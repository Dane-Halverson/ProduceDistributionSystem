#include <catch2/catch_test_macros.hpp>
#include "Distributor.h"
#include <ProduceInterface.h>

TEST_CASE("Distributor Basic Operations")
{
    //can be made
    Distributor d("produce.json", "schools.json");
    d.stageNext();
    //get get basic information
    REQUIRE(d.getNextEperation() == "Sep 20 2021");
    REQUIRE(d.getNextType() == "tomatoes");
    d.stageNext();
    //pass works and can cycle back to passed produce
    REQUIRE(d.getNextType() == "carrots");
    d.pass();
    d.stageNext();
    d.pass();
    d.stageNext();
    REQUIRE(d.getNextType() == "carrots");

    //get get school info
    REQUIRE( d.getSchoolCount() == 5);
    REQUIRE(d.getSchoolType(0) == "middle");

    //return false on staging if empty
    d.stageNext();
    d.stageNext();
    REQUIRE(!d.stageNext());
}
