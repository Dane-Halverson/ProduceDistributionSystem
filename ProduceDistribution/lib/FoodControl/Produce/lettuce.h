#pragma once

#include "../ProduceInterface.h"
#include <Date.h>

/**
* @author Dane Halverson
* @file lettuce.h
* @date 17
*/

class lettuce : public Produce
{
private:
    int life = 4;

public:
   lettuce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);

   std::string getType() override {return "lettuce";}
};

lettuce::lettuce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{
    experation.setDate(date);
    experation.addDays(life - daysSincePick);
}


