#include "School.h"
#include <string>
/**
 * @author Dane Halverson
 * @file School.cpp
 * @date 10/05/2022
 */
School::School(std::string schoolname, std::string schooltype, double schoolbudget) 
: name(schoolname), type(schooltype), budget(schoolbudget)
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
