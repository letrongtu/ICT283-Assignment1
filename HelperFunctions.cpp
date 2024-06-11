#include "HelperFunctions.h"

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


