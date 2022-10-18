#include <nlohmann/json.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fstream>
#include <string>
#include <iostream>

using json = nlohmann::json;

TEST_CASE ("json parser tests") {
    std::string filename = "test.json";
    std::ifstream inputFileStream(filename);

    json j;
    inputFileStream >> j;
    std::string out = j[ "date" ];
    REQUIRE(out == "Sept 18 2021");

    json j2 = j[ "produce" ];
    std::cout << j2[ 0 ][ "type" ];

}
