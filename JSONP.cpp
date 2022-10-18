#include "JSONP.h"

/**
 * @author Dane Halverson
 * @author Teddy Jeddeloh
 * @file JSONP.cpp
 * @date 10/18/2022
*/

void JSONP::parse() {
    //parce attempt
    std::ifstream inputFileStream(produceFilename);

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

JSONP::JSONP(std::string pf, std::string sf) : produceFilename(pf), schoolFilename(sf)
{
    std::ifstream produceStream(pf);
    std::ifstream schoolStream(sf);

    produceStream >> Produce;
    schoolStream >> Schools;
}
