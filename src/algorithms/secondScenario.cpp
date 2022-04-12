//
// Created by Eduardo Correia on 09/04/2022.
//


#include "secondScenario.h"

void secondScenario::compute() {
    unsigned int results[3];

    auto start = std::chrono::system_clock::now();
    unsigned int maximumValue = getMax3(results[0] = computeByWeight(),results[1] = computeByVolume(),results[2] = computeByWeightToVolume());
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    printResult(maximumValue);
    printComputationTime(elapsed_seconds,end_time);
}

secondScenario::secondScenario(const vector<request>& requests, const vector<truck>& trucks) : abstractAlgorithm(requests, trucks) {
    sortedRequests = requests;
    sortedTrucks = trucks;
    bestScenario = 0;
}

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

//Sort requests by biggest volume to reward ratio
bool secondScenario::requestVolumeToReward(const request &a, const request &b){
    return ((double)a.volume*a.reward) > ((double)b.volume*b.reward);
}

//Sort trucks by biggest volume to cost ratio
bool secondScenario::truckVolumeToCost(const truck &a, const truck &b){
    return ((double)a.maxVolume/a.cost) > ((double)b.maxVolume/b.cost);
}

//Sort requests by biggest V*W to reward ratio
bool secondScenario::wvRatioToReward(const request &a, const request &b){
    return ((double)a.volume*a.weight*a.reward) > ((double)b.volume*b.weight*b.reward);
}

//Sort trucks by biggest V*W to cost ratio
bool secondScenario::wvRatioToCost(const truck &a, const truck &b){
    return ((double)(a.maxVolume*a.maxVolume)/a.cost) > ((double)(b.maxVolume*b.maxWeight)/b.cost);
}



unsigned int secondScenario::computeByWeight() {

    std::queue<request> requestQueue;
    unsigned int truckIndex = 0;

    //Sort requests by weight * reward (higher first), and sort trucks by weight/cost (higher first)
    std::sort(sortedRequests.begin(), sortedRequests.end(), requestWeightToReward);
    std::sort(sortedTrucks.begin(), sortedTrucks.end(), truckWeightToCost);
    outputTrucks[0] = sortedTrucks;

    //Insert requests into a request queue
    for(auto request : sortedRequests)
       requestQueue.push(request);

    while(!requestQueue.empty()){
        request currentRequest = requestQueue.front();
        if(!checkAndInsert(currentRequest,outputTrucks[0].at(truckIndex))){
            truckIndex++;
            if(truckIndex >= outputTrucks[0].size()) break;
        }
        requestQueue.pop();
    }

    return calculateProfit(outputTrucks[0]);

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
    outputTrucks[1] = sortedTrucks;

    //Insert requests into a request queue
    for(auto request : sortedRequests)
        requestQueue.push(request);

    while(!requestQueue.empty()){
        request currentRequest = requestQueue.front();
        if(!checkAndInsert(currentRequest,outputTrucks[1].at(truckIndex))){
            truckIndex++;
            if(truckIndex >= outputTrucks[1].size()) break;
        }
        requestQueue.pop();
    }

    return calculateProfit(outputTrucks[1]);
}

unsigned int secondScenario::computeByWeightToVolume() {
    std::queue<request> requestQueue;
    unsigned int truckIndex = 0;

    //Sort requests by weight * reward (higher first), and sort trucks by weight/cost (higher first)
    std::sort(sortedRequests.begin(), sortedRequests.end(), wvRatioToReward);
    std::sort(sortedTrucks.begin(), sortedTrucks.end(), wvRatioToCost);
    outputTrucks[2] = sortedTrucks;

    //Insert requests into a request queue
    for(auto request : sortedRequests)
        requestQueue.push(request);

    while(!requestQueue.empty()){
        request currentRequest = requestQueue.front();
        if(!checkAndInsert(currentRequest,outputTrucks[2].at(truckIndex))){
            truckIndex++;
            if(truckIndex >= outputTrucks[2].size()) break;
        }
        requestQueue.pop();
    }

    return calculateProfit(outputTrucks[2]);
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

unsigned int secondScenario::getMax3(unsigned int value1,unsigned int value2,unsigned int value3) {
    unsigned int max = value1;
    if(value2 > value1 && value2 > value3){
        max = value2;
        bestScenario = 1;
    }
    else if(value3 > value1 && value3 > value2){
        max = value3;
        bestScenario = 2;
    }
    return max;
}

unsigned int secondScenario::calculateCost(const vector<truck> &trucks) {
    unsigned int cost = 0;
    for(const auto& truck : trucks){
        cost+= truck.cost;
    }
    return cost;
}

unsigned int secondScenario::numberOfRequests(const vector<truck> &trucks) {
    unsigned int counter = 0;
    for(const auto& truck : trucks){
        counter += truck.truckLoad.size();
    }
    return counter;
}

void secondScenario::printResult(unsigned int maximumValue) {
    cout << "-*-------------  Report Scenario 2  ------------------*-" << endl;
    cout << " |--> Truck Details: " << endl;
    cout << " |        Number of Trucks: " << trucks.size() << endl;
    cout << " |        Percentage of Trucks used: " << (double)outputTrucks[bestScenario].size()/(double)trucks.size() * 100.0 << "%" << endl;
    cout << " |--> Deliveries: " << endl;
    cout << " |        Number of Deliveries: " << requests.size() << endl;
    cout << " |        Delivered: " << ((double)numberOfRequests(outputTrucks[bestScenario])/(double)requests.size()) * 100.0 << "%" << endl;
    cout << " |--> Balance: " << endl;
    cout << " |        Truck Cost: " << calculateCost(outputTrucks[bestScenario]) << "$" << endl;
    cout << " |        Total profit: " << maximumValue << "$" << endl;
    cout << "-*----------------------------------------------------*-" << endl;
}

void secondScenario::printComputationTime(chrono::duration<double> elapsed_seconds, time_t end_time) {
    cout << "-*-------------  Computation Time --------------------*-" << endl;
    cout << " |--> Time Details: " << endl;
    cout << " |        Elapsed Time: " << elapsed_seconds.count() << "s" << endl;
    cout << " |        Finished Computation At: " << std::ctime(&end_time);
    cout << "-*----------------------------------------------------*-" << endl;
}



