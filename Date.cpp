#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

Date::Date(const Date &date) : day(date.day), month(date.month), year(date.year)
{
}

int Date::GetDay() const
{
    return day;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetYear() const
{
    return year;
}

void Date::SetDay(int d)
{
    day = d;
}

void Date::SetMonth(int m)
{
    month = m;
}

void Date::SetYear(int y)
{
    year = y;
}
