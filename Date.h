#pragma once
#include <string>
/**
 * @author Dane Halverson
 * @file Date.h
 * @date 10/03/2022
 */

/**
 * @class Date
 * @brief takes in a string and converts it to an integer
 * converts a date in the format "Mon DD YYYY" into the amount of days since the year 0.
 */
class Date {
    private:
    std::string date;
    int years, months, days;
    int full;

    int daysSinceZero();

    public:

    /// @brief constructor for date
    /// @param dateString Mon DD YYYY
    Date(std::string dateString);

    Date() = default;

    /// @brief gets an int of how many days it's been since year 0
    /// @return the amount of days since 0
    int getDaysSinceZero() { return full;}

    /// @brief adds to the the stored amount of days
    /// @param num the amount of days to add
    void addDays(int num) {full += num;}

    /**
     * @brief takes in a new string to set the date to
     * @param datestring 
     */
    void setDate(std::string datestring);

    std::string getString();
    
};
