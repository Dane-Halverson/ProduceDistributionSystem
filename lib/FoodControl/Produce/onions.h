#pragma once

#include "../ProduceInterface.h"
#include <Date.h>

/**
* @author Dane Halverson
* @file onions.h
* @date 17
*/

class onions : public Produce
{
private:
    int life = 12;

public:
   onions(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

onions::onions(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


