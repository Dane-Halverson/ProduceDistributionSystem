#include <catch2/catch_test_macros.hpp>
#include "Distributor.h"
#include <ProduceInterface.h>


TEST_CASE("Distributor Basic Operations") {
    Distributor d("produce.json", "schools.json");
    d.stageNext();
    std::cout << d.getNextEperation();
    //REQUIRE(d.getNextType() == "tomatoes");
    
}
