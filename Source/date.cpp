#include <iostream>
#include <string>
#include "../Header/date.h"

Date::Date(int date) : x(date)
{
    if (!Date::isValid())
        x = 17000301;
}

int Date::getYear()
{
    return x / 10000;
}

int Date::getMonth()
{
    return (x % 10000) / 100;
}

int Date::getDay()
{
    return (x % 100);
}

int Date::getQuater()
{
    return (getMonth() + 2) / 3;
}

void Date::print()
{
    std::cout << weekdayAsText(weekday()) << " " << getDay() << "/" << getMonth() << "-" << getYear() << std::endl;
}

void Date::print(int x)
{
    std::cout << x << std::endl;
}

bool Date::isLeapYear()
{
    if (Date::getYear() % 4 == 0 && getYear() % 100 != 0)
    {
        return true;
    }
    else if (getYear() % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::isValid()
{
    if (x < 17000301 || x > 99999999)
        return false;

    if (getYear() < 1700 || getYear() > 9999)
        return false;

    if (getMonth() < 1 || getMonth() > 12)
        return false;

    if (getDay() < 1 || getDay() > 31)
        return false;

    if (getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11)
    {
        if (getDay() > 30)
        {
            return false;
        }
    }

    if (getMonth() == 2)
    {
        if (isLeapYear() && getDay() > 29)
        {
            return false;
        }
        else if (!isLeapYear() && getDay() > 28)
        {
            return false;
        }
    }
    return true;
}

int Date::oldIncrementDate()
{
    int xDay = x;
    do
    {
        x++;
    } while (!isValid());
    int temp = x;
    x = xDay;
    return temp;
}

void Date::incrementDate()
{
    x = oldIncrementDate();
}

int Date::differenceInDays(Date future)
{
    int diff = 0;
    int xDay = x;
    if (x < future.x)
    {
        while (x != future.x)
        {
            x = oldIncrementDate();
            diff++;
        };
        x = xDay;
        return diff;
    }
    else
    {
        return diff;
    }
}

int Date::dayOfTheYear()
{
    int xDay = x;
    x = 17000101 + (getYear() - 1700) * 10000;
    int day = 1;
    if (x < xDay)
    {
        while (x != xDay)
        {
            x = oldIncrementDate();
            day++;
        };
        x = xDay;
        return day;
    }
    return day;
}

int Date::weekday()
{
    int xDay = x;
    x = 17000301;
    int day = 0;
    if (x < xDay)
    {
        while (x != xDay)
        {
            x = oldIncrementDate();
            day++;
        };
        x = xDay;
        return day % 7 + 1;
    }
    return day % 7 + 1;
}

std::string Date::weekdayAsText(int weekday)
{
    std::string weekdays[] = {"mon", "tue", "wen", "thu", "fri", "sat", "sun"};
    return weekdays[weekday - 1];
}
