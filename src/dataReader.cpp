//
// Created by dudud on 06/04/2022.
//

#include "dataReader.h"



dataReader::dataReader(const char* truckPath,const char* requestPath) {
    numberTrucks = 0;
    numberRequests = 0;
    strcpy(truckFilePath,truckPath);
    strcpy(requestFilePath,requestPath);
}

bool dataReader::readFixed(int n) {
    std::ifstream file;
    std::string stringBuffer;
    int counter = 0;
    std::cout<<"teste2"<<std::endl;

    file.open(truckFilePath,std::ios::in);
    if(!file.is_open()) return false;

    std::cout<<"teste2"<<std::endl;
    getline(file,stringBuffer);
    while(getline(file,stringBuffer) && counter < n){
        std::cout << stringBuffer << std::endl;
        counter++;
    }

    file.close();
    return true;
}

bool dataReader::readRandom(int n) {
    return false;
}

unsigned int dataReader::getNumberTrucks() {
    return numberTrucks;
}

unsigned int dataReader::getNumberRequests() {
    return numberRequests;
}

std::vector<request> dataReader::getRequests() {
    return requests;
}

std::vector<truck> dataReader::getTrucks() {
    return trucks;
}

char *dataReader::getTruckPath() {
    return truckFilePath;
}

char *dataReader::getRequestPath() {
    return requestFilePath;
}

