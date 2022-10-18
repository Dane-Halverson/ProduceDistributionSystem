#include <iostream>
#include "Date.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Basic Date operations") {
    //date can be constructed
    Date date1("Oct 5 2022");
    // date can calculate a psudo number of days since 0
    REQUIRE(date1.getDaysSinceZero() == 738798);
    // days can be added to a date
    date1.addDays(10);
    REQUIRE(date1.getDaysSinceZero() == 738808);
    //date can be constructed then set to a number
    Date date2;
    date2.setDate("Oct 5 2022");
    REQUIRE(date2.getDaysSinceZero() == 738798);
    //date parser works with alternitive date formats
    Date date3("OCT 5 2022");
    Date date4("OcToBeR 5 2022");
    Date date5("10/05/2022");
    REQUIRE(date3.getDaysSinceZero() == 738798);
    REQUIRE(date4.getDaysSinceZero() == 738798);
    REQUIRE(date5.getDaysSinceZero() == 738798);


    //dates are all correct
    Date d1("10/08/2000"), d2("Octob 04 2022"), d3("OCT 5 2022"), d4("OCTOBER 6 2022"), d5("January 2 2025");
    REQUIRE(d1.getDaysSinceZero() < d2.getDaysSinceZero());
    REQUIRE(d2.getDaysSinceZero() < d3.getDaysSinceZero());
    REQUIRE(d3.getDaysSinceZero() < d4.getDaysSinceZero());
    REQUIRE(d3.getDaysSinceZero() < d5.getDaysSinceZero());

    Date d6("Oct 20 2022"), d7("Oct 19 2022");
    REQUIRE(d6.getDaysSinceZero() > d7.getDaysSinceZero());

    //can make strings
    REQUIRE(d2.getString() == "Oct 8 2022");
}

