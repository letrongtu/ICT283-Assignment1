#ifndef DataStructure_H
#define DataStructure_H

#include "Vector.h"
#include "Date.h"
#include "Time.h"

struct WeatherRecord{
    Date date;
    Time time;
    double speed;
    double airTemp;
    double solarRad;
};

typedef Vector<WeatherRecord> WeatherLog;
#endif
