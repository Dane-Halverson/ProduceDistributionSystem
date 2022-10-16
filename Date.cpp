#include "Date.h"
#include <cmath>
#include "DateParser.h"
#include <map>

/**
 * @file Date.cpp
 * @author Dane Halverson
 * @date 10/05/2022
 */

Date::Date(std::string dateString) : date(dateString)
{
    DateParser d(dateString);
    days = d.getDay();
    months = d.getMonth();
    years = d.getYear();
    full = daysSinceZero();
}

void Date::setDate(std::string dateString)
{
    DateParser d(dateString);
    date = dateString;
    days = d.getDay();
    months = d.getMonth();
    years = d.getYear();
    full = daysSinceZero();
}

int Date::daysSinceZero()
{

    int monthDays = 0;

    switch (months)
    {
    case 12:
        monthDays += 334; // adds novmember
        break;
    case 11:
        monthDays += 304; // adds october
        break;
    case 10:
        monthDays += 273; // adds september
        break;
    case 9:
        monthDays += 243; // adds August
        break;
    case 8:
        monthDays += 212; // adds july
        break;
    case 7:
        monthDays += 181; // adds june
        break;
    case 6:
        monthDays += 151; // adds may
        break;
    case 5:
        monthDays += 120; // adds april
        break;
    case 4:
        monthDays += 90; // adds march
        break;
    case 3:
        monthDays += 59; // adds february (adds leap days later)
        break;
    case 2:
        monthDays += 31; // adds january
        break;
    case 1:
        monthDays += 0; // adds nothing, no months have passed
        break;
    }
    int leapyears = 0;

    if (months > 2)
    {
        leapyears = floor(years / 4) - floor(years / 100) + floor(years / 400);
    }
    else
    {
        leapyears = floor((years - 1) / 4) - floor((years - 1) / 100) + floor((years - 1) / 400);
    }

    return leapyears + (years * 365) + monthDays + days;
}

void Date::addDays(int num)
{
    full += num;

    for (int i = 0; i < num; ++i)
    {
        if ((months == 2) && (days == 29) && !(years % 4 == 0) && ((years % 100 == 0) != !(years % 400)))
        {
            ++months;
            days = 1;
        }
        else if ((months == 2) && (days == 28))
        {
            ++months;
            days = 1;

        }
        else if ( ( (months == 4) || (months == 6) || (months == 9) || (months == 11) ) && (days == 30)) {
            ++months;
            days = 1;
        }
        else if ((months == 12) && (days == 31)) {
            ++years;
            months = 1;
            days = 1;
        }
        else if (days == 31) {
            ++months;
            days = 1;
        }
        else {
            ++days;
        }
    }
}

std::string Date::getString()
{
    return DateParser::makeString(months, days, years);
}
