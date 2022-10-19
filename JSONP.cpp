#include "JSONP.h"

/**
 * @author Dane Halverson
 * @author Teddy Jeddeloh
 * @file JSONP.cpp
 * @date 10/18/2022
 */

JSONP::JSONP(std::string pf, std::string sf) : produceFilename(pf), schoolFilename(sf)
{
    // parse of produce file
    std::ifstream produceStream(pf);
    // parse of farm file
    std::ifstream schoolStream(sf);
    // inserting files into json object
    produceStream >> Produce;
    schoolStream >> Schools;
}

std::string JSONP::getDate()
{
    return Produce["date"];
}

int JSONP::getDaysSincePicked()
{
    return Produce[ "daysSincePicked" ];
}

int JSONP::getProduceCount()
{
    nlohmann::json produceArr = Produce["produce"];
    return produceArr.size();
}

int JSONP::getProduceWeight(int i)
{
    nlohmann::json produceArr = Produce["produce"];
    return produceArr[i]["weight"];
}

std::string JSONP::getProduceType(int i)
{
    nlohmann::json produceArr = Produce["produce"];
    return produceArr[i]["type"];
}

bool JSONP::produceHasExperation(int i)
{
    nlohmann::json produceArr = Produce["produce"];
    return produceArr[i].contains("experation");
}

std::string JSONP::getProduceExperation(int i) 
{
    if (!produceHasExperation(i)) {
        std::string message = "getProduceExperation(int) called on an object with an experation defined\n";
        message += "use produceHasExperation(int) to check if it has and experation defined\n";
        throw message;
    }
    nlohmann::json produceArr = Produce["produce"];
    return produceArr[i]["experation"];
}

////////////////////////////////////////
//              School
////////////////////////////////////////
int JSONP::getSchoolCount()
{
    nlohmann::json schoolArr = Schools["schools"];
    return schoolArr.size();
}

std::string JSONP::getSchool(int i)
{
    nlohmann::json schoolArr = Schools["schools"];
    return schoolArr[i]["name"];
}

// may wont seperate functions for getting each datapiece ie. days since pick, date, weight, farm etc.
std::string JSONP::getSchoolType(int i)
{
    nlohmann::json schoolArr = Schools["schools"];
    return schoolArr[i]["type"];
}

double JSONP::getSchoolBudget(int i)
{
    nlohmann::json schoolArr = Schools["schools"];
    return schoolArr[i]["budget"];
}
