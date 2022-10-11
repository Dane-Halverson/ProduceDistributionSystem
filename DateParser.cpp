/**
 * @author Dane Halverson
 * @file DateParser.cpp
 * @date 10/05/2022
 */

#include "DateParser.h"
#include <string>
#include <cctype>
#include <iostream>

DateParser::DateParser(std::string date) {
    ParseDate(date);
}

void DateParser::ParseDate(std::string date) {
    if (isalpha(date[0])) {
        ParseMonDDYYYY(date);
    }
    else if (isdigit(date[0])) {
        ParseMMDDYYYY(date);
    }
}


void DateParser::ParseMonDDYYYY(std::string date) {
    int found = date.find_first_of(' ');
    std::string months = date.substr(0, 3);
    int j = 0;
    for (auto i : months) {
        months[j] = tolower(i);
        ++j;
    }
    if (months == "jan") months = 1;
    else if (months == "feb") month = 2;
    else if (months == "mar") month = 3;
    else if (months == "apr") month = 4;
    else if (months == "may") month = 5;
    else if (months == "jun") month = 6;
    else if (months == "jul") month = 7;
    else if (months == "aug") month = 8;
    else if (months == "sep") month = 9;
    else if (months == "oct") month = 10;
    else if (months == "nov") month = 11;
    else if (months == "dec") month = 12;
    
    date = date.substr(found+1, date.size());

    found = date.find_first_of(' ');
    day = std::stoi(date.substr(0, found));
    date = date.substr(found+1, date.size());

    year = std::stoi(date);
  

}

void DateParser::ParseMMDDYYYY(std::string date) {
    int found = date.find_first_of('/');
    std::string months = date.substr(0, found);
    month = std::stoi(months);

    date = date.substr(found+1, date.size());

    found = date.find_first_of('/');
    day = std::stoi(date.substr(0, found));
    date = date.substr(found+1, date.size());

    year = std::stoi(date);

}

int DateParser::getDay() {
    return day;
}

int DateParser::getMonth() {
    return month;
}

int DateParser::getYear() {
    return year;
}