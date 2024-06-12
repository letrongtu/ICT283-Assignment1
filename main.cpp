#include "DataStructure.h"
#include "DataProcessor.h"
#include "MenuFunctions.h"
#include <iostream>

int main()
{
    WeatherLog weather_data;
    readFileName(weather_data);

    menu(weather_data);

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Exiting..........................***" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    return 0;
}
