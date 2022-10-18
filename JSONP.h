#pragma once

/**
 * @author Dane Halverson
 * @author Teddy Jeddeloh
 * @file JSONP.h
 * @date 10/18/2022
*/



#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>



/**
 * @class JSONP
 * @brief Class for parsing json file of produce and school objects
 */
class JSONP {
private:
    std::string produceFilename;
    std::string schoolFilename;
    nlohmann::json Produce;
    nlohmann::json Schools;
public:
    /**
     * @brief default constructor for JSONP
     * @param pf filename for produce json file
     * @param sf filename for schools json file
     */
    JSONP(std::string pf, std::string sf);

    void parse();
    ~JSONP() = default;
    std::string getDate();
    std::string getProducecount();
    int getProduce(int i);
    int getProduceInfo(int i, std::string data);
    bool produceHasDate();

    int getSchoolCount();
    std::string getSchool(int i);

    //may wont seperate functions for getting each datapiece ie. days since pick, date, weight, farm etc.
    std::string getSchoolInfo(int i, std::string data);


    
};
