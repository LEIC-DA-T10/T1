#ifndef DA_T1_DATAIO_H
#define DA_T1_DATAIO_H


#include <vector>
#include "dataStructs.h"
#include <iostream>
#include <fstream>
#include <cstring>


#define TRUCK_PRINT_PATH "../data/output/current_trucks.txt"
#define REQUEST_PRINT_PATH "../data/output/current_requests.txt"



class dataIO {
private:
    std::vector<request> requests;
    std::vector<truck> trucks;
    unsigned int numberTrucks = 0;
    unsigned int numberRequests = 0;
    const char* truckPath;
    const char* requestPath;
public:
    dataIO(const char* truckPath, const char* requestPath);
    bool readTrucksFixed(int start, int finish);
    bool readRequestsFixed(int start, int finish);
    bool readTrucksRandom(int n);
    bool readRequestsRandom(int n);
    unsigned int getNumberTrucks();
    unsigned int getNumberRequests();
    std::vector<request> getRequests();
    std::vector<truck> getTrucks();
    const char* getTruckPath();
    const char* getRequestPath();
    void printRequests(char answer);
    void printTrucks(char answer);
    bool checkNumberTrucks();
    bool checkNumberRequests();
};


#endif //DA_T1_DATAIO_H