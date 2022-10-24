#include "JSONP.h"

/**
 * @author Dane Halverson
 * @author Teddy Jeddeloh
 * @file JSONP.cpp
 * @date 10/18/2022
 */

JSONP::JSONP(std::string pf) : produceFilename(pf)
{
    //parse of produce file
    std::ifstream produceStream(pf);
    //parse of farm file
    //inserting files into json object
    produceStream >> Produce;
}

std::string JSONP::getDate(){
    return Produce["date"];
}

int JSONP::getDaysSincePicked()
{
    return Produce[ "daysSincePicked" ];
}

int JSONP::getProduceCount()
{
    nlohmann::json produceArr = Produce["produce"];
    return int(produceArr.size());
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

double JSONP::getCPP(int i)
{
    nlohmann::json produceArr = Produce["produce"];
    return produceArr[i]["costPerPound"];
}

bool JSONP::produceHasDateOfPick(int i)
{
    nlohmann::json produceArr = Produce["produce"];
    return produceArr[i].contains("dateofpick");
}

std::string JSONP::getProduceDateOfPick(int i) 
{
    if (!produceHasDateOfPick(i)) 
{
        std::string message = "getdateofpick(int) called on an object without dateofpick defined\n";
        message += "use produceHasDateOfPick(int) to check if it has a date of pick defined\n";
        throw message;
    }
    nlohmann::json produceArr = Produce["produce"];
    return produceArr[i]["dateofpick"];
}

std::string JSONP::getFarm(int i)
{
    nlohmann::json produceArr = Produce["produce"];
    return produceArr[i]["farm"];
}


