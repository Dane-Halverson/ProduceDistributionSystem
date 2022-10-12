#include "JSONP.h"

JSONP::JSONP(std::string filename)
{
    //parce attempt
    std::ifstream inputFileStream(filename);

    // ///////////////////////////////////////
    // open file and parse by json class
    // ///////////////////////////////////////
    nlohmann::json j;
    inputFileStream >> j;

    std::cout << "JSON element (date) = " << j["date"] << std::endl;
    nlohmann::json jsonArrayData = j["produce"];
    std::cout << "JSON Array size = " << jsonArrayData.size() << std::endl;
    for (size_t i = 0; i < jsonArrayData.size(); i++)
    {
        std::cout << "produce contains" << jsonArrayData[0][i] << std::endl;
    }
    
}

JSONP::~JSONP()
{
}

