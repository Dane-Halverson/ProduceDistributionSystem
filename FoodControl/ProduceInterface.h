#pragma once
/**
 * @author Dane Halverson
 * @file ProduceInterface.h
 * @date 10/03/2022
 */

#include "../Date.h"


class Produce {
    protected:
    int life;
    double pricePerPound;
    unsigned int weight;
    Date experation;
    std::string farm;

    public:
    /**
     * @brief constructor for a produce object
     * @param n the weight of the produce
     * @param date the current date. "Mon DD YYYY" "MM/DD/YYYY" "Month DD YYYY"
     * @param daysSincePick days since the produce was picked
     * @param nameOfFarm name of the farm its from
     * @param price prive per pound of the produce
     */
    Produce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);

    virtual ~Produce() = default;


    /**
     * @return an int of the numbers of days past the year 0 that it expires
     */
    int getExperInt();

    /**
     * @return the price per pound of the produce
     */
    double getPricePerPound() const;

    /**
     * @return The total weight of the produce
     */
    int getWeight() const;

    /**
     * @brief sets the total weight to a number
     * @param amount the number to set the weight to
     */
    void setWeight(int amount);

    /**
     * @return the name of the farm 
     */
    std::string getFarm() const;

};

Produce::Produce(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price) : weight(n), farm(nameOfFarm)
{
    pricePerPound = price;
    experation.setDate(date);
    experation.addDays(life - daysSincePick);
}

int Produce::getExperInt() {
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
