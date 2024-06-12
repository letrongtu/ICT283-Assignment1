#ifndef HelperFunctions_h
#define HelperFunctions_h

#include "Vector.h"
#include <string>

bool isValidHeader(const Vector<std::string>& headers);
int getHeaderIndex(const std::string& header, const Vector<std::string>& headers);
int readChoice();
int readYear();
int readMonth();
double calculateAverage(const Vector<double>& array);
double calculateSD(const Vector<double>& array);
double calculateSum(const Vector<double>& array);

#endif
