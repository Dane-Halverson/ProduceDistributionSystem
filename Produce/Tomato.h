#pragma once
#include "ProduceInterface.h"
#include "Date.h"
/**
 * @author Dane Halverson
 * @file ProduceClasses.h
 * @date 10/03/2022
 * @brief a file for storing the dervived classes from ProduceInterface
 */

class Tomato : public Produce
{
private:
    int life = 3;

public:
    Tomato(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);
};

Tomato::Tomato(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)
: Produce(n, date, daysSincePick, nameOfFarm, price)
{}
