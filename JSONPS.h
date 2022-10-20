#pragma once

/**
 * @author Dane Halverson
 * @author Teddy Jeddeloh
 * @file JSONP.h
 * @date 10/20/2022
 */

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>

class JSONPS
{
private:
    std::string schoolFilename;
    nlohmann::json Schools;
public:
    JSONPS(std::string sf);
    ~JSONPS() = default;

    /**
     * @brief get the count of schools in the json file
     * @return an int of the count
     */
    int getSchoolCount();

    /**
     * @brief gets the name of the chosen school
     * @param i the number or index of the school to get the name of
     * @return a string of the school name
     */
    std::string getSchool(int i);
    
    /**
     * @brief get the type of school middle, high etc.
     * @param i the number or index of the school to get the type of
     * @return a string of the type of school
     */
    std::string getSchoolType(int i);

    /**
     * @brief get the amount of budget of a school defined in the json file
     * @param i the number or index of the school to get the budget of
     * @return a double with the total budget of the school
     */
    double getSchoolBudget(int i);
};

JSONPS::JSONPS(std::string sf)
{
}

JSONPS::~JSONPS()
{
}
