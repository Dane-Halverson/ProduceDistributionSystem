#include "ProduceInterface.h"

Produce::Produce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price) : weight(n), farm(nameOfFarm)
{
    pricePerPound = price;
    experation.setDate(date);
    experation.addDays(life - daysSincePick);
}

int Produce::getExperInt() const {
    return experation.getDaysSinceZero();
}

double Produce::getPricePerPound() const {
    return pricePerPound;
}

int Produce::getWeight() const {
    return weight;
}

void Produce::setWeight(int amount) {
    weight = amount;
}

std::string Produce::getFarm() const {
    return farm;
}