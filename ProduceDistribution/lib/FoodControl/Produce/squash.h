#pragma once

#include "../ProduceInterface.h"
#include <Date.h>

/**
* @author Dane Halverson
* @file squash.h
* @date 17
*/

class squash : public Produce
{
private:
    int life = 30;

public:
   squash(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
   std::string getType() override {return "squash";}
};

squash::squash(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{
    experation.setDate(date);
    experation.addDays(life - daysSincePick);
}


