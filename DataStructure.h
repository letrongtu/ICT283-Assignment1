#ifndef DataStructure_H
#define DataStructure_H

#include "Vector.h"
#include "Date.h"
#include "Time.h"
#include <string>

const double speedExchangeRate = 3.6;

const double radExchangeRate = 0.000167;

const int monthCounts = 12;

const std::string MonthsNames[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

struct WeatherRecord{
    Date date;
    Time time;
    double speed;
    double airTemp;
    double solarRad;
};

typedef Vector<WeatherRecord> WeatherLog;
#endif
