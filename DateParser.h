#pragma once
/**
 * @author Dane Halverson
 * @file DateParser.h
 * @date 10/05/2022
 */
#include <string>


/**
 * @class DateParser
 * @brief class to take in a string and turn it into ints for day, month, and year
 */
class DateParser {
    private:
    int year = 0;
    int month = 0;
    int day = 0;

    void ParseMonDDYYYY(std::string date);
    void ParseMMDDYYYY(std::string date);

    public: 
    /**
     * @brief takes ina  date and runs parse date on construction
     * @param date 
     */
    DateParser(std::string date);

    /**
     * @brief takes in a string in the date format, Mon DD YYYY, Month DD YYYY, MONTH D YYYY, Mont DD YYYY, MM/DD/YYYY
     * or M/D/YYYY
     * @pre date format must be in a format listed above
     * @param date the string for it to parse
     */
    void ParseDate(std::string date);

    /**
     * @brief gets the year in int
     * @return year
     */
    int getYear();

    /**
     * @brief gets the month in int (1-12)
     * @return month
     */
    int getMonth();
    
    /**
     * @brief gets the day in int
     * @return day
     */
    int getDay();
};

