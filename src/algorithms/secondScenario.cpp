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

//Sort requests by biggest weight to reward ratio
bool secondScenario::requestVolumeToReward(const request &a, const request &b){
    return ((double)a.volume*a.reward) > ((double)b.volume*b.reward);
}

//Sort trucks by biggest weight to cost ratio
bool secondScenario::truckVolumeToCost(const truck &a, const truck &b){
    return ((double)a.maxVolume/a.cost) > ((double)b.maxVolume/b.cost);
}

secondScenario::secondScenario(const vector<request>& requests, const vector<truck>& trucks) : abstractAlgorithm(requests, trucks) {
    sortedRequests = requests;
    sortedTrucks = trucks;
}


void secondScenario::compute() {
    cout << "!----------------------!" << endl;
    cout << computeByWeight() << endl;
    cout << computeByVolume() << endl;
    cout << "!----------------------!" << endl;
}


int secondScenario::computeByWeight() {

    std::queue<request> requestQueue;
    unsigned int truckIndex = 0;

    //Sort requests by weight * reward (higher first), and sort trucks by weight/cost (higher first)
    std::sort(sortedRequests.begin(), sortedRequests.end(), requestWeightToReward);
    std::sort(sortedTrucks.begin(), sortedTrucks.end(), truckWeightToCost);
    weightOutput = sortedTrucks;

    //Insert requests into a request queue
    for(auto request : sortedRequests)
       requestQueue.push(request);

    while(!requestQueue.empty()){
        request currentRequest = requestQueue.front();
        if(!checkAndInsert(currentRequest,weightOutput.at(truckIndex))){
            truckIndex++;
            if(truckIndex >= weightOutput.size()) break;
        }
        requestQueue.pop();
    }

    return calculateProfit(weightOutput);

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

unsigned int secondScenario::computeByVolume() {
    std::queue<request> requestQueue;
    unsigned int truckIndex = 0;

    //Sort requests by weight * reward (higher first), and sort trucks by weight/cost (higher first)
    std::sort(sortedRequests.begin(), sortedRequests.end(), requestVolumeToReward);
    std::sort(sortedTrucks.begin(), sortedTrucks.end(), truckVolumeToCost);
    volumeOutput = sortedTrucks;

    //Insert requests into a request queue
    for(auto request : sortedRequests)
        requestQueue.push(request);

    while(!requestQueue.empty()){
        request currentRequest = requestQueue.front();
        if(!checkAndInsert(currentRequest,volumeOutput.at(truckIndex))){
            truckIndex++;
            if(truckIndex >= volumeOutput.size()) break;
        }
        requestQueue.pop();
    }

    return calculateProfit(volumeOutput);
}

unsigned int secondScenario::computeByWeightToVolume() {
    return 0;
}

int secondScenario::calculateProfit(vector<truck> &trucks) {
    int profit = 0; int truckCounter = 0;
    vector<int> trucksToRemove;
    for(const auto& truck : trucks){
        int truckReward = 0;
        for(auto request : truck.truckLoad){
            truckReward += (int)request.reward;
        }
        truckReward -= (int)truck.cost;

        if(truckReward < 0) trucksToRemove.push_back(truckCounter);
        else profit += truckReward;
    }
    //Removing un-profitable trucks.
    for(auto index : trucksToRemove){
        truck &truck = trucks.at(index);
        truck.truckLoad.clear();
        trucks.erase(trucks.begin()+index);
    }

    return profit;
}


