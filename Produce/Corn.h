#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file Corn.h
* @date 10/06/2022
*/

class Corn : public Produce
{
private:
    int life = 10;

public:
   Corn(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

Corn::Corn(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


