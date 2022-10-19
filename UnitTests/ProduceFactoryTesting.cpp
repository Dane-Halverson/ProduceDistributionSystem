#include <catch2/catch_test_macros.hpp>
#include <ProduceFactory.h>

TEST_CASE("Testing Produce Factory") {
    ProduceFactory testing;
    std::shared_ptr<Produce> foo = testing.makeProduce("lettuce", 28, "10/18/2022", 2, "Farm Name", 19.28);
}; 
