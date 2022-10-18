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



class JSONP {
private:
    std::string filename;
    nlohmann::json Produce;
    nlohmann::json Schools;
public:
    JSONP(const std::string fn) : filename(fn) {}
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
