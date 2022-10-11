#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file Carrot.h
* @date 10/06/2022
*/

class Carrot : public Produce
{
private:
    int life = 12;

public:
   Carrot(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

Carrot::Carrot(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


