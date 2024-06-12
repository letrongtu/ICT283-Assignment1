#include "MenuFunctions.h"
#include "HelperFunctions.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void menu(const WeatherLog &weather_data)
{
    int choice;
    while(true){
        displayMenu();
        choice = readChoice();

        if(processChoice(weather_data, choice)){
            break;
        }
    }
}

void displayMenu(){
    std::cout << "Menu: Type(" << "\n"
         << "1 : Display Average Wind Speed And Sample Standard Deviation In A Month Of A Year." << "\n"
         << "2 : Display Average Ambient Air Temperature And Sample Standard Deviation For Each Month Of A Year." << "\n"
         << "3 : Display Total Solar Radiation For Each Month Of A Specified Year." << "\n"
         << "4 : Display Average Wind Speed, Average Ambient Air Temperature, And Total Solar Radiation For Each Month Of A Year." << "\n"
         << "5 : Exit the program.)" << "\n"
         << "-------------------------------------------------------------------------------------------------------------------"
         << std::endl;
}

bool processChoice(const WeatherLog& weather_data, int choice)
{
    switch(choice){
        case 1:
            firstCase(weather_data);
            return false;
            break;
        case 2:
            secondCase(weather_data);
            return false;
            break;
        case 3:
            thirdCase(weather_data);
            return false;
            break;
        case 4:
            fourthCase(weather_data);
            return false;
            break;
        case 5:
            return true;

        default:
            std::cout << "Invalid Option, Please enter an integer from 1 to 5!" << std::endl;
            return false;
    }
}

void firstCase(const WeatherLog &weather_data)
{
    int year = readYear();
    int month = readMonth();

    Vector<double> speedData;

    for(int i = 0; i < weather_data.Size(); i++){
        if(weather_data[i].date.GetYear() == year && weather_data[i].date.GetMonth() == month){
            speedData.push_back(weather_data[i].speed * speedExchangeRate);
        }
    }

    firstCaseOutput(speedData, month, year);
}

void firstCaseOutput(const Vector<double>& speedData, int month, int year){
    std::cout << MonthsNames[month-1] << " " << year << ": ";

    if(speedData.Size() != 0){
        double avg = calculateAverage(speedData);
        double sd = calculateSD(speedData);

        std::cout << "\nAverage speed: " << std::fixed << std::setprecision(1) << avg << " km/h" << std::endl;
        std::cout << "Sample stdev: " << sd << std::endl;
    }
    else{
        std::cout << "No Data" << std::endl;
    }

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void secondCase(const WeatherLog &weather_data)
{
    int year = readYear();

    Vector<double> temp;

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << year << std::endl;
    for(int month = 1; month <= monthCounts; month++){
        for(int i = 0; i < weather_data.Size(); i++){
            if(weather_data[i].date.GetYear() == year && weather_data[i].date.GetMonth() == month){
                temp.push_back(weather_data[i].airTemp);
            }
        }

        tempEachMonthOutput(temp, month);

        temp.clear();
    }
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void tempEachMonthOutput(const Vector<double>& temp, int month){
    std::cout << MonthsNames[month-1] << ": ";

    if(temp.Size() != 0){
        double avg = calculateAverage(temp);
        double sd = calculateSD(temp);

        std::cout << "average: " << std::fixed << std::setprecision(1) << avg << " degrees C, stdev: " << sd << std::endl;
    }
    else{
        std::cout << "No data" << std::endl;
    }
}

void thirdCase(const WeatherLog &weather_data)
{
    int year = readYear();

    Vector<double> solarRads;

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << year << std::endl;
    for(int month = 1; month <= monthCounts; month++){
        for(int i = 0; i < weather_data.Size(); i++){
            if(weather_data[i].date.GetYear() == year && weather_data[i].date.GetMonth() == month){
                solarRads.push_back(weather_data[i].solarRad * radExchangeRate);
            }
        }

        radEachMonthOutput(solarRads, month);

        solarRads.clear();
    }
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void radEachMonthOutput(const Vector<double>& solarRads, int month){
    std::cout << MonthsNames[month-1] << ": ";

    if(solarRads.Size() != 0){
        double sum = calculateSum(solarRads);

        std::cout << std::fixed << std::setprecision(1) << sum << "kWh/m2" << std::endl;
    }
    else{
        std::cout << "No data" << std::endl;
    }
}

void fourthCase(const WeatherLog &weather_data)
{
    int year = readYear();

    Vector<double> speed, temp, solarRads;
    bool hasData = false;

    std::ofstream outFile("WindTempSolar.csv");

    if(!outFile.is_open()){
        std::cout << "Error openning WindTempSolar.csv!" << std::endl;
        return;
    }

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    outFile << year << std::endl;

    for(int month = 1; month <= monthCounts; month++){
        for(int i = 0; i < weather_data.Size(); i++){
            if(weather_data[i].date.GetYear() == year && weather_data[i].date.GetMonth() == month){
                speed.push_back(weather_data[i].speed * speedExchangeRate);
                temp.push_back(weather_data[i].airTemp);
                solarRads.push_back(weather_data[i].solarRad * radExchangeRate);
            }
        }

        if(hasData == false){
            hasData = forthCaseOutput(outFile, speed, temp, solarRads, month);
        }
        else{
            forthCaseOutput(outFile, speed, temp, solarRads, month);
        }

        speed.clear();
        temp.clear();
        solarRads.clear();
    }

    if(hasData == false){
        outFile << "No data" << std::endl;
    }

    std::cout << "Write Data to WindTempSolar.csv Successfully" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    outFile.close();
}

bool forthCaseOutput(std::ofstream& outFile, const Vector<double>& speed, const Vector<double>& temp, const Vector<double>& solarRads, int month){
    if(speed.Size() == 0){
        return false;
    }

    double avgSpeed = calculateAverage(speed);
    double sdSpeed = calculateSD(speed);
    double avgTemp = calculateAverage(temp);
    double sdTemp = calculateSD(temp);
    double radTotal = calculateSum(solarRads);

    outFile << std::fixed << std::setprecision(1) << MonthsNames[month-1] << ", " << "" << avgSpeed << "(" << sdSpeed << "), " << avgTemp << "(" << sdTemp << "), " << radTotal << std::endl;

    return true;
}
