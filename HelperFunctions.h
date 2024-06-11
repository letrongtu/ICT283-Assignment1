#ifndef HelperFunctions_h
#define HelperFunctions_h

#include "Vector.h"
#include <string>

bool isValidHeader(const Vector<std::string>& headers);
int getHeaderIndex(const std::string& header, const Vector<std::string>& headers);


#endif
