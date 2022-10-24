#include "JSONPS.h"

JSONPS::JSONPS(std::string sf) 
{
    std::ifstream schoolStream(sf);
    schoolStream >> Schools;
}


int JSONPS::getSchoolCount()
{
    nlohmann::json schoolArr = Schools["schools"];
    return int(schoolArr.size());
}

std::string JSONPS::getSchool(int i)
{
    nlohmann::json schoolArr = Schools["schools"];
    return schoolArr[i]["name"];
}

// may wont seperate functions for getting each datapiece ie. days since pick, date, weight, farm etc.
std::string JSONPS::getSchoolType(int i)
{
    nlohmann::json schoolArr = Schools["schools"];
    return schoolArr[i]["type"];
}

double JSONPS::getSchoolBudget(int i)
{
    nlohmann::json schoolArr = Schools["schools"];
    return schoolArr[i]["budget"];
}
