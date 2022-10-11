#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file Onion.h
* @date 10/06/2022
*/

class Onion : public Produce
{
private:
    int life = 12;

public:
   Onion(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

Onion::Onion(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


