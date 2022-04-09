//
// Created by dudud on 06/04/2022.
//

#include <set>
#include <random>
#include "dataIO.h"

using namespace std;



set<unsigned int> generateRandomSet(unsigned int distinct,unsigned int max){
    set<unsigned int> numbers;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, max);

    while (numbers.size() < distinct) {
        numbers.insert((unsigned int) dist(mt));
    }
    return numbers;
}


vector<string> split (const string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

dataIO::dataIO(const char* truckPath, const char* requestPath) {
    numberTrucks = 0;
    numberRequests = 0;
    this->truckPath = truckPath;
    this->requestPath = requestPath;
}

bool dataIO::readTrucksFixed(int start, int finish) {
    fstream file;
    string stringBuffer;
    int counter = 0;

    file.open(truckPath, ios::in);
    if(!file) return false;

    for(int i = 0; i <= start; i++){
        getline(file,stringBuffer);
    }

    if(numberTrucks == 0) checkNumberTrucks();


    while(getline(file,stringBuffer) && counter < (finish-start)){
        vector<string> splitString = split(stringBuffer," ");

        truck truckBuffer;
        truckBuffer.maxVolume = stoi(splitString.at(0));
        truckBuffer.maxWeight = stoi(splitString.at(1));
        truckBuffer.cost = stoi(splitString.at(2));

        trucks.push_back(truckBuffer);
        counter++;
    }

    file.close();
    return true;
}

bool dataIO::readRequestsFixed(int start, int finish) {
    fstream file;
    string stringBuffer;
    int counter = 0;

    file.open(requestPath, ios::in);
    if(!file) return false;

    if(numberRequests == 0) checkNumberRequests();

    for(int i = 0; i <= start; i++){
        getline(file,stringBuffer);
    }

    while(getline(file,stringBuffer) && counter < (finish-start)){
        vector<string> splitString = split(stringBuffer," ");

        request requestBuffer;
        requestBuffer.volume = stoi(splitString.at(0));
        requestBuffer.weight = stoi(splitString.at(1));
        requestBuffer.reward = stoi(splitString.at(2));
        requestBuffer.duration = stoi(splitString.at(3));

        requests.push_back(requestBuffer);
        counter++;
    }

    file.close();
    return true;
}


bool dataIO::readTrucksRandom(int n) {
    fstream file;
    string stringBuffer;
    int counter = 0;

    file.open(truckPath, ios::in);
    if(!file) return false;

    if(numberTrucks == 0) checkNumberTrucks();
    set<unsigned int> randomIndexes = generateRandomSet(n,numberTrucks);

    while(getline(file,stringBuffer) && counter < numberTrucks){
        if(randomIndexes.find(counter) != randomIndexes.end()){
            vector<string> splitString = split(stringBuffer," ");

            truck truckBuffer;
            truckBuffer.maxVolume = stoi(splitString.at(0));
            truckBuffer.maxWeight = stoi(splitString.at(1));
            truckBuffer.cost = stoi(splitString.at(2));

            trucks.push_back(truckBuffer);
        }
        counter++;
    }

    return true;
}

bool dataIO::readRequestsRandom(int n) {
    fstream file;
    string stringBuffer;
    int counter = 0;

    file.open(requestPath, ios::in);
    if(!file) return false;

    if(numberRequests == 0) checkNumberRequests();
    set<unsigned int> randomIndexes = generateRandomSet(n,numberRequests);

    while(getline(file,stringBuffer) && counter < numberRequests){
        if(randomIndexes.find(counter) != randomIndexes.end()){
            vector<string> splitString = split(stringBuffer," ");

            request requestBuffer;
            requestBuffer.volume = stoi(splitString.at(0));
            requestBuffer.weight = stoi(splitString.at(1));
            requestBuffer.reward = stoi(splitString.at(2));
            requestBuffer.duration = stoi(splitString.at(3));

            requests.push_back(requestBuffer);
        }
        counter++;
    }

    return true;
}


unsigned int dataIO::getNumberTrucks() {
    return numberTrucks;
}

unsigned int dataIO::getNumberRequests() {
    return numberRequests;
}

std::vector<request> dataIO::getRequests() {
    return requests;
}

std::vector<truck> dataIO::getTrucks() {
    return trucks;
}

const char *dataIO::getTruckPath() {
    return truckPath;
}

const char *dataIO::getRequestPath() {
    return requestPath;
}

void dataIO::printRequests() {
    for (auto request : requests){
        std::cout << request.volume << " ";
        std::cout << request.weight << " ";
        std::cout << request.reward << " ";
        std::cout << request.duration << " " << std::endl;
    }
}

void dataIO::printTrucks() {
    for (auto truck : trucks){
        std::cout << truck.maxVolume << " ";
        std::cout << truck.maxWeight << " ";
        std::cout << truck.cost << " " << endl;
    }
}

bool dataIO::checkNumberTrucks() {
    fstream file;
    string stringBuffer;
    int counter = 0;

    file.open(truckPath, ios::in);
    if(!file) return false;

    while(getline(file,stringBuffer)){
        counter++;
    }
    numberTrucks = counter-1;
    return true;
}

bool dataIO::checkNumberRequests() {
    fstream file;
    string stringBuffer;
    int counter = 0;

    file.open(requestPath, ios::in);
    if(!file) return false;

    while(getline(file,stringBuffer)){
        counter++;
    }
    numberRequests = counter-1;
    return true;
}



