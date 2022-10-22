#include <catch2/catch_test_macros.hpp>
#include "Distributor.h"
#include <ProduceInterface.h>


TEST_CASE("Distributor Basic Operations") {
    Distributor d("../testJSONP.json", "../testJSONS.json");
    d.stageNext();
    //REQUIRE(d.getNextType() == "tomatoes");
    
}
