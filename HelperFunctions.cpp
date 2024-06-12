#include "HelperFunctions.h"
#include <iostream>
#include <cmath>

bool isValidHeader(const Vector<std::string>& headers){
    int numOfValidHeaders = 0;

    for(int i = 0; i < headers.Size(); i++){
        if(headers[i] == "WAST"){
            numOfValidHeaders += 1;
        }
        else if (headers[i] == "S"){
            numOfValidHeaders += 2;
        }
        else if(headers[i] == "SR"){
            numOfValidHeaders += 3;
        }
        else if(headers[i] == "T"){
            numOfValidHeaders += 4;
        }
    }

    if(numOfValidHeaders != (1+2+3+4)){
        return false;
    }

    return true;
}

int getHeaderIndex(const std::string& header, const Vector<std::string>& headers)
{
    for(int i = 0; i < headers.Size(); i++){
        if(header == headers[i]){
            return i;
        }
    }

    return -1;
}

int readChoice()
{
    while(true){
        std::cout << "Enter your choice (1-5):" << std::endl;

        std::string choice;
        std::cin >> choice;

        try{
            return stoi(choice);
        }
        catch(const std::invalid_argument& e){
            std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Please enter an integer!" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
        }
    }
}

int readYear(){
    while(true){
        std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Enter year:" << std::endl;

        std::string year;
        std::cin >> year;

        try{
            return stoi(year);
        }
        catch(const std::invalid_argument& e){
            std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Please enter an integer!" << std::endl;
        }
    }
}

int readMonth(){
    while(true){
        std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Enter month:" << std::endl;

        std::string month;
        std::cin >> month;

        try{
            std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            return stoi(month);
        }
        catch(const std::invalid_argument& e){
            std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Please enter an integer!" << std::endl;
        }
    }
}

double calculateAverage(const Vector<double>& array){
    double sum = calculateSum(array);

    return sum/array.Size();
}

double calculateSD(const Vector<double>& array){
    double mean = calculateAverage(array);

    double sum = 0;
    for(int i = 0; i < array.Size(); i++){
        sum += ((array[i] - mean) * (array[i] - mean));
    }

    return std::sqrt(sum/array.Size());
}

double calculateSum(const Vector<double>& array){
    double sum = 0;

    for(int i = 0; i < array.Size(); i++){
        sum += array[i];
    }

    return sum;
}
