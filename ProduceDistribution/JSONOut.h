#pragma once

/**
 * @author Teddy Jeddeloh
 * @file JSONOut.h
 * @date  10/26/2022
 * @brief uses nlohmann json format to outsource a json file
 */

#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
using namespace nlohmann;

class JSONOut
{
private:
    //make fstream object
    std::ofstream madefileProd ("../schoolUpdate.json", std::ofstream::out);
    std::ofstream madefileSch ("../schoolUpdate.json", std::ofstream::out);
    //make json object
    json ProdJSON;
    json schoolsJSON;
    //for holding produce
    json ProduceJ;
    //create a vector for produce 
    std::vector<json> prodVec;
public:
    JSONOut(std::string date);
    ~JSONOut();

    void setDate(std::string s);
    // no set days since picked BECAUSE it matters for each individual produce
    void setType(std::string s);
    void setWeight(int w);
    void setCost(float f);
    void setFarm(std::string s);
    void setDoP(std::string s);
    void vecPush();
    void OUT();
    void setSchool(std::string type, std::string name, float budget, int i);
};