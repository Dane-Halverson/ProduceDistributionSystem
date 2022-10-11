#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file Lettuce.h
* @date 10/06/2022
*/

class Lettuce : public Produce
{
private:
    int life = 4;

public:
   Lettuce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

Lettuce::Lettuce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


