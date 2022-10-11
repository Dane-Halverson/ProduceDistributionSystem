#pragma once

#include "ProduceInterface.h"
#include "Date.h"

/**
* @author Dane Halverson
* @file Avocados.h
* @date 10/06/2022
*/

class Avocados : public Produce
{
private:
    int life = 7;

public:
   Avocados(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

Avocados::Avocados(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}


