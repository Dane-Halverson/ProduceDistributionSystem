#pragma once
#include <memory>
#include <string>
#include "ProduceInterface.h"


/**
 * @author Marshall Bluhm
 * @file ProduceFactory.h
 * @date 10/17/2022
 */


/**
 * @brief Takes in a vector of strings containg produce data and assigns that produce of the same type
 * @param std::vector<string>
*/
class ProduceFactory {
    public:
        /**
         * @brief default constructor
        */
        ProduceFactory() = default;
        /**
         * @brief default deconstructor
        */
        ~ProduceFactory() = default;

        /**
         * @brief Sets the produce given a the data of {type, weight, date, daysSincePicked, nameOfFarm,  price}
         * @param std::string type, int n, std::string date, int daysSincePick, std::string nameOfFarm, double price
        */
        std::shared_ptr<Produce> makeProduce(std::string type, int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);   
};



