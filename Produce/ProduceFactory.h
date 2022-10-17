#pragma once
#include <vector>
#include <string>
#include <iostream>
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
         * @brief Sets the produce given a vector of strings
         * @param std::vector<std::string>
        */
        ProduceFactory(std::vector<std::string> data);
        
        /**
         * @brief default deconstructor
        */
        ~ProduceFactory() = default;

    private:
        //Helper methods for ProduceFactory
    
};

