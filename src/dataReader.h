
#ifndef DA_T1_DATAREADER_H
#define DA_T1_DATAREADER_H


#include <vector>
#include "dataStructs.h"
#include <iostream>
#include <fstream>
#include <cstring>



class dataReader {
private:
    std::vector<request> requests;
    std::vector<truck> trucks;
    unsigned int numberTrucks;
    unsigned int numberRequests;
    char* truckFilePath;
    char* requestFilePath;
public:
    explicit dataReader(const char* truckPath,const char* requestPath);
    bool readFixed(int n);
    bool readRandom(int n);
    unsigned int getNumberTrucks();
    unsigned int getNumberRequests();
    std::vector<request> getRequests();
    std::vector<truck> getTrucks();
    char* getTruckPath();
    char* getRequestPath();
};


#endif //DA_T1_DATAREADER_H
