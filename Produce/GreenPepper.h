#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file GreenPepper.h
* @date 10/06/2022
*/

class GreenPepper : public Produce
{
private:
    int life = 60;

public:
   GreenPepper(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

GreenPepper::GreenPepper(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


