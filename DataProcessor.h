#ifndef DataProcessor_H
#define DataProcessor_H

#include "DataStructure.h"
#include <fstream>

void readFileName(WeatherLog& weather_data);
void readData(std::ifstream& inSource, WeatherLog& weather_data);
void readHeader(Vector<std::string>& header, const std::string& line);
bool readWeatherRecord(const std::string line, WeatherRecord& record, int wastIndex, int speedIndex, int solarRadIndex, int airTempIndex);
bool readDateTime(const std::string& cell, Date& date, Time& time);
bool readDate(const std::string& dateTemplate, Date& date);
bool readTime(const std::string& timeTemplate, Time& time);

#endif
