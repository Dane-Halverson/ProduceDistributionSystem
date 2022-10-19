#pragma once

#include "../ProduceInterface.h"
#include <Date.h>

/**
* @author Dane Halverson
* @file apple.h
* @date 17
*/

class apple : public Produce
{
private:
    int life = 12;

public:
   apple(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

apple::apple(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


