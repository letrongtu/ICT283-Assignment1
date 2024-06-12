#ifndef MenuFunctions_h
#define MenuFunctions_h
#include "DataStructure.h"

void menu(const WeatherLog& weather_data);
void displayMenu();
bool processChoice(const WeatherLog& weather_data, int choice);
void firstCase(const WeatherLog& weather_data);
void firstCaseOutput(const Vector<double>& speedData, int month, int year);
void secondCase(const WeatherLog& weather_data);
void tempEachMonthOutput(const Vector<double>& temp, int month);
void thirdCase(const WeatherLog& weather_data);
void radEachMonthOutput(const Vector<double>& solarRads, int month);
void fourthCase(const WeatherLog& weather_data);
bool forthCaseOutput(std::ofstream& outFile, const Vector<double>& speed, const Vector<double>& temp, const Vector<double>& solarRads, int month);
#endif
