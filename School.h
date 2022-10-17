#pragma once
/**
 * @file School.cpp
 * @author Dane Halverson
 * @date 10/02/2022
 */

#include <string>
#include <list>
#include <memory>
#include "ProduceInterface.h"


/**
 * @class School
 * @brief a class that defines a school that needs produce
 */
class School {
    private:
    std::string name;
    std::string type;
    double budget;
    std::list<std::shared_ptr<Produce>> boughtProduce;


    public:

    /**
     * @brief constructor for school class
     * @param schoolname the name of the school
     * @param schooltype hs, ms, em
     * @param schoolbudget the budget for produce
     */
    School(std::string schoolname, std::string schooltype, double schoolbudget);

    ~School() = default;

    /**
     * @brief function to get the name of the school
     * @return name 
     */
    std::string getName();

    /**
     * @brief gets the type of school
     * @return type
     */
    std::string getType();

    /**
     * @brief gets the budget for buying produce
     * @return budget
     */
    double getBudget();

    /**
     * @brief sets the budget of the school
     * @param amount 
     */
    void setBudget(double amount);

    void addProduce(std::shared_ptr<Produce> p) {boughtProduce.push_back(p);}

    std::list<std::shared_ptr<Produce>> getAllProduce() {return boughtProduce;}
};

