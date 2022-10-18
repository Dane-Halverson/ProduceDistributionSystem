#pragma once
#include "ProduceInterface.h"
#include <memory>
#include <string>


#include "Produce/Tomato.h"
/**
 * @author Dane Halverson
 * @file Produce Factory
 * @date 10/03/2022
 */



using ProPtr = std::shared_ptr<Produce>;


/**
 * @brief class to produce produce objects
 * @class Produce factory
 */
class ProduceFactory
{
private:

public:
ProduceFactory() = default;
~ProduceFactory() = default;
/**
 * @brief creates a produce object and returns it
 * @param type the type of produce to make (ie Tomato)
 * @param n the weight of the produce  
 * @param date current date (Mon DD YYYY)
 * @param daysSincePick how many days since the produce was picked
 * @param nameOfFarm name of the farm it's from
 * @return the created object
 */
ProPtr MakeProd(std::string type, int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);

};


