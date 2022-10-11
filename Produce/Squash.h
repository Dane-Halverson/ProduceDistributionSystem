#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file Squash.h
* @date 10/06/2022
*/

class Squash : public Produce
{
private:
    int life = 30;

public:
   Squash(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

Squash::Squash(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


