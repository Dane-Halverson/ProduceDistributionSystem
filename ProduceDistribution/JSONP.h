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
class JSONP
{
private:
    std::string produceFilename;
    nlohmann::json Produce;

public:
    /**
     * @brief default constructor for JSONP
     * @param pf filename for produce json file
     * @param sf filename for schools json file
     */
    JSONP(std::string pf);

    ~JSONP() = default;

    /**
     * @brief gets cost per pound
     * @param i the index to get
     * @return double costperpound
     */
    double getCPP(int i);

    std::string getFarm(int i);
    /**
     * @brief function to get the date from the json file. should be the date of the the current day.
     * @return a string of the date
     */
    std::string getDate();

    /**
     * @brief get how many produce objects are in the json file
     * @return an int of how many produce objects are in the json file
     */
    int getProduceCount();

    /**
     * @brief gets the wieght of a json defined produce
     * @param i the number or index to get the weight of
     * @return the weight of the chosen produce
     */
    int getProduceWeight(int i);

    /**
     * @brief function to get the type of a produce defined in the json file
     * @param i the number or index of the produce to get the type of
     * @return a string of the type (ie. "tomatos")
     */
    std::string getProduceType(int i);

    /**
     * @brief function to check if the produce has an date of pick defined in the json
     * @param i the number or index of produce to check from the json file
     * @return true if it has an "dateofpick" element
     */
    bool produceHasDateOfPick(int i);

    /**
     * @brief function to get the dateofpick element of a json produce object
     * @param i the number or index to check
     * @return a string of the dateofpick date
     * @throws if called on an object without a defined dateofpick
     */
    std::string getProduceDateOfPick(int i);

    /**
     * @brief returns the days since picked 
     * @return an int of the days sinced picked
     */
    int getDaysSincePicked();

    /**
     * @brief get the count of schools in the json file
     * @return an int of the count
     */
    int getSchoolCount();

    /**cd 
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
