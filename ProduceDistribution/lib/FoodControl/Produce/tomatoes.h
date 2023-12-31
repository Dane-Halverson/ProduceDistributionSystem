#pragma once

#include "../ProduceInterface.h"
#include <Date.h>

/**
* @author Dane Halverson
* @file tomatoes.h
* @date 10
*/

class tomatoes : public Produce
{
private:
    int life = 3;

public:
   tomatoes(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);

   std::string getType() override {return "tomatoes";}
};


tomatoes::tomatoes(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{
    experation.setDate(date);
    experation.addDays(life - daysSincePick);
}


