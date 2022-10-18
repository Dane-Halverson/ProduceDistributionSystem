#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file lettuce.h
* @date 10/17/2022
*/

class lettuce : public Produce
{
private:
    int life = 4;

public:
   lettuce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

lettuce::lettuce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


