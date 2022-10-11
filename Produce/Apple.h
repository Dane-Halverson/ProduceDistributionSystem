#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file Apple.h
* @date 10/06/2022
*/

class Apple : public Produce
{
private:
    int life = 12;

public:
   Apple(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

Apple::Apple(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


