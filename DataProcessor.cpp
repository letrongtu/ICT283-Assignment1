#include "DataProcessor.h"
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <sstream>

void readFileName(WeatherLog &weather_data)
{
    std::ifstream inSource("./data/data_source.txt");
    if(!inSource.is_open()){
        std::cout << "Error opening source file!" << std::endl;
        return;
    }

    std::string filename;

    getline(inSource, filename);
    inSource.close();

    std::cout << "Reading: " << filename << std::endl;
    filename = "./data/" + filename;
    inSource.open(filename);
    if(!inSource.is_open()){
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    readData(inSource, weather_data);
}

void readData(std::ifstream &inSource, WeatherLog &weather_data)
{
    std::string line;
    getline(inSource, line);

    Vector<std::string> headers;
    readHeader(headers, line);
    if(!isValidHeader(headers)){
        std::cout << "The file doesn't contain the required headers" << std::endl;
        return;
    }

    const int wastIndex = getHeaderIndex("WAST", headers);
    const int speedIndex = getHeaderIndex("S", headers);
    const int solarRadIndex = getHeaderIndex("SR", headers);
    const int airTempIndex = getHeaderIndex("T", headers);

    Vector<std::string> cells;
    WeatherRecord record;
    int lineRead = 0;
    int lineDropped = 0;

    while(getline(inSource, line)){
        if(readWeatherRecord(line, record, wastIndex, speedIndex, solarRadIndex, airTempIndex)){
            weather_data.push_back(record);
            lineRead++;
        }
        else{
            lineDropped++;
        }
    }

    std::cout << "<<<Data read successfully>>>\n"
              << "Line Read: " << lineRead << "\n"
              << "Line Dropped: " << lineDropped << "\n"
              << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void readHeader(Vector<std::string>& headers, const std::string& line){
    std::string header;
    std::stringstream ss(line);

    while(getline(ss, header, ',')){
        headers.push_back(header);
    }
}

bool readWeatherRecord(const std::string line, WeatherRecord& record, int wastIndex, int speedIndex, int solarRadIndex, int airTempIndex){
    std::string cell;
    std::stringstream ss(line);

    int currIndex = 0;
    while(getline(ss, cell, ',')){
        try{
            if(currIndex == wastIndex){
                if(!readDateTime(cell, record.date, record.time)){
                    return false;
                }
            }
            else if(currIndex == speedIndex){
                record.speed = std::stod(cell);
            }
            else if(currIndex == solarRadIndex){
                record.solarRad = std::stod(cell);
            }
            else if(currIndex == airTempIndex){
                record.airTemp = std::stod(cell);
            }
        }
        catch (std::invalid_argument& e){
            return false;
        }

        currIndex++;
    }

    return true;
}

bool readDateTime(const std::string& cell, Date& date, Time& time){
    std::istringstream ss(cell);
    std::string dateTemplate, timeTemplate;

    if(!(getline(ss, dateTemplate, ' ') && getline(ss, timeTemplate))){
        return false;
    }

    return readDate(dateTemplate, date) && readTime(timeTemplate, time);
}

bool readDate(const std::string& dateTemplate, Date& date){
    std::istringstream ss(dateTemplate);
    int day, month, year;
    char firstDelimiter, secondDelimiter;

    if(!(ss >> day >> firstDelimiter >> month >> secondDelimiter >> year) || (firstDelimiter != '/') || (secondDelimiter != '/')){
        return false;
    }
    date.SetDay(day);
    date.SetMonth(month);
    date.SetYear(year);

    return true;
}

bool readTime(const std::string& timeTemplate, Time& time){
    std::istringstream ss(timeTemplate);
    int hour, minute;
    char delimiter;

    if(!(ss >> hour >> delimiter >> minute) || (delimiter != ':')){
        return false;
    }

    time.SetHour(hour);
    time.SetMinute(minute);

    return true;
}
