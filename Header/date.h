#pragma once
#include <iostream>
#include <string>

class Date
{
private:
    int x;

public:
    Date(int date);
    int getYear();
    int getMonth();
    int getQuater();
    int getDay();
    void print();
    void print(int x);
    bool isLeapYear();
    bool isValid();
    int oldIncrementDate();
    void incrementDate();
    int differenceInDays(Date future);
    int dayOfTheYear();
    int weekday();
    std::string weekdayAsText(int weekday);
};
