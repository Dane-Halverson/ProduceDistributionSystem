#include "School.h"
#include <string>
/**
 * @author Dane Halverson
 * @file School.cpp
 * @date 10/05/2022
 */
School::School(std::string schoolname, std::string schooltype, double schoolbudget)
    : name(schoolname), type(schooltype), budget(schoolbudget), boughtProduce(20)
{
}

std::string School::getName()
{
    return name;
}

std::string School::getType()
{
    return type;
}

double School::getBudget()
{
    return budget;
}

void School::setBudget(double amount)
{
    budget = amount;
}

void School::addProduce(std::shared_ptr<Produce> p)
{
    boughtProduce.push_back(p);
}

std::vector<std::shared_ptr<Produce>> School::getProduceVec() {
    return boughtProduce;
}

