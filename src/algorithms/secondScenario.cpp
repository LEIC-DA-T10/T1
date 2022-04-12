//
// Created by Eduardo Correia on 09/04/2022.
//


#include <iostream>
#include <algorithm>
#include <queue>
#include "secondScenario.h"

void secondScenario::printTrucks(const vector<truck> &trucks) {
    for (const auto& truck: trucks) {
        cout << truck.maxVolume << " " << truck.maxWeight << " " << truck.cost << endl;
    }
}

void secondScenario::printRequests(const vector<request> &requests) {
    for (const auto& request: requests) {
        cout << request.volume << " " << request.weight << " " << request.reward << endl;
    }
}
//Sort requests by biggest weight to reward ratio
bool secondScenario::requestWeightToReward(const request &a, const request &b){
    return ((double)a.weight*a.reward) > ((double)b.weight*b.reward);
}

//Sort trucks by biggest weight to cost ratio
bool secondScenario::truckWeightToCost(const truck &a, const truck &b){
    return ((double)a.maxWeight/a.cost) > ((double)b.maxWeight/b.cost);
}

secondScenario::secondScenario(const vector<request>& requests, const vector<truck>& trucks) : abstractAlgorithm(requests, trucks) {
    sortedRequests = requests;
    sortedTrucks = trucks;
}


void secondScenario::compute() {
    cout << "!----------------------!" << endl;
    cout << computeByWeight() << endl;
    cout << "!----------------------!" << endl;
}


int secondScenario::computeByWeight() {

    std::queue<request> requestQueue;
    unsigned int truckIndex = 0;
    unsigned int cost = 0;
    int profit = 0;

    //Sort requests by weight * reward (higher first), and sort trucks by weight/cost (higher first)
    std::sort(sortedRequests.begin(), sortedRequests.end(), requestWeightToReward);
    std::sort(sortedTrucks.begin(), sortedTrucks.end(), truckWeightToCost);
    weightOutput = sortedTrucks;

    //Insert requests into a request queue
    for(auto request : sortedRequests)
       requestQueue.push(request);

    while(!requestQueue.empty()){
        request currentRequest = requestQueue.front();
        for(unsigned int i = truckIndex; i < weightOutput.size(); i++){
            if(checkAndInsert(currentRequest,weightOutput.at(i))){
                profit += (int)currentRequest.reward;
                break;
            }
        }
        incrementTruckIndex(truckIndex,weightOutput.size());
        requestQueue.pop();
    }

    return profit;
}


bool secondScenario::checkAndInsert(request requestToInsert, truck &truckToInsert) {
    if(requestToInsert.weight <= truckToInsert.maxWeight && requestToInsert.volume <= truckToInsert.maxVolume){
        truckToInsert.truckLoad.push_back(requestToInsert);
        truckToInsert.maxWeight -= requestToInsert.weight;
        truckToInsert.maxVolume -= requestToInsert.volume;
        return true;
    }
    return false;
}

void secondScenario::incrementTruckIndex(unsigned int &index, unsigned int max) {
    index++;
    if(index >= max) index = 0;
}


unsigned int secondScenario::computeByVolume() {
    return 0;
}

unsigned int secondScenario::computeByWeightToVolume() {
    return 0;
}


