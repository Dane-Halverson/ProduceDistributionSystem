#pragma once

#include "../ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file carrots.h
* @date 10
*/

class carrots : public Produce
{
private:
    int life = 12;

public:
   carrots(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

carrots::carrots(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


