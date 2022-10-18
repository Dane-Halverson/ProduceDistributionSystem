#include "JSONP.h"

void JSONP::parse() {
    //parce attempt
    std::ifstream inputFileStream(filename);

    // ///////////////////////////////////////
    // open file and parse by json class
    // ///////////////////////////////////////
    nlohmann::json j;
    inputFileStream >> j;

    std::cout << "JSON element (date) = " << j["date"] << std::endl;
    std::cout << j["daysSincePicked"] << std::endl;
    nlohmann::json jsonArrayData = j["produce"];
    std::cout << "JSON Array size = " << jsonArrayData.size() << std::endl;
    for (size_t i = 0; i < jsonArrayData.size(); i++)
    {
        std::cout << "produce contains" << jsonArrayData[i]["type"] << std::endl;
    }
    
}
