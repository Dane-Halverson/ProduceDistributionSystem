#pragma once

#include "../ProduceInterface.h"
#include <Date.h>

/**
* @author Dane Halverson
* @file carrots.h
* @date 17
*/

class carrots : public Produce
{
private:
    int life = 12;

public:
   carrots(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
   std::string getType() override {return "carrots";}
};

carrots::carrots(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{
    experation.setDate(date);
    experation.addDays(life - daysSincePick);
}


