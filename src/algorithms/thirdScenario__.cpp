//
// Created by Ze Carvalho on 16/04/2022.
//

#include <chrono>
#include "thirdScenario__.h"

thirdScenario__::thirdScenario__(const vector<request> &requests1, const vector<truck> &trucks1) : abstractAlgorithm(requests1, trucks1) {
    requests = requests1;
    trucks = trucks1;
}

void thirdScenario__::compute() {
    auto start = std::chrono::system_clock::now();
    if (trucks.size() > 1)cout << "---- WARNING : MORE THAN 1 TRUCK PROVIDED ONLY THE FIRST WILL BE CONSIDERED ----" << endl;
    vector<int> requestsDuration;
    vector<int> bestDelivery;
    vector<vector<int>> res;
    requests = fitsTruck();

    for (auto & request : requests) requestsDuration.push_back(request.duration);

    res = subsets(requestsDuration);
    bestDelivery = bestOption(res);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    printTruckDetails();
    printOnlyMax(bestDelivery);
    printComputationTime(elapsed_seconds,end_time);
}


/// recursive function to find all the subsets following the backtracking implementation
/// designed to function with positive numbers not tested for negative

void thirdScenario__::calculateDeliverySubsets(vector<int>& deliveryVector, vector<vector<int>>& res, vector<int>& subset, int index){
    res.push_back(subset);
    for (int i = index; i < deliveryVector.size(); i++) {
        subset.push_back(deliveryVector[i]);
        calculateDeliverySubsets(deliveryVector, res, subset, i + 1);
        subset.pop_back();
    }
}
/// identify all the subsets and return after analysis

vector<vector<int>> thirdScenario__::subsets(vector<int>& deliveryVector){
    int index = 0;
    vector<int> subset;
    vector<vector<int> > res;
    calculateDeliverySubsets(deliveryVector, res, subset, index);
    res = analiseRes(res);
    return res;
}
///Select the best option following the scenario objective, can me adapted to new scenarios just by changing this function

vector<int> thirdScenario__::bestOption(vector<vector<int>> &res) {
    int bestNum = -1;
    int bestTime = INT32_MAX;
    vector<int> bestOption;
    int time;
    int numReq;
    for ( int i = 0 ; i < res.size(); i++){
        time = res[res.size()-1][i];
        numReq = res[res.size()-1][i+1];
        if(bestNum < numReq){
            bestTime = time;
            bestNum = numReq;
        }
        else if (bestNum == numReq && bestTime > time){
            bestTime = time;
        }
        i++;
    }

    bestOption.push_back(bestTime);
    bestOption.push_back(bestNum);
    return bestOption;
}

///major res analysis

vector<vector<int>> thirdScenario__::analiseRes(const vector<vector<int>>& res) const {
    int subsetValue;
    vector<int> validValue;
    vector<vector<int>> validVector;
    for (const auto & re : res) {
        subsetValue = 0;
        for (int j = 0; j < re.size(); j++){
            subsetValue += re[j];
        }
        if (subsetValue <= timeFrame) {
            validValue.push_back(subsetValue);
            validValue.push_back(re.size());
            validVector.push_back(validValue);
        }
    }
    sort(validVector.begin(), validVector.end());
    return validVector;
}

///screening functions

bool thirdScenario__::isDeliverable(int i) const {
    auto request = requests.at(i);
    if (express.maxVolume > request.volume && express.maxWeight > request.weight && request.duration + usedTime <= timeFrame) return true;
    return false;
}

vector<request> thirdScenario__::fitsTruck() {
    vector<request> deliverable;
    for (int i = 0 ; i < requests.size();i ++){
        if (isDeliverable(i)) deliverable.push_back(requests.at(i));
    }
    return deliverable;
}

///Printing functions

void thirdScenario__::printTruckDetails() const {
    cout << "-*-------------  Report Scenario 3  ------------------*-" << endl;
    cout << " |--> Truck Details: " << endl;
    cout << " |        Truck Maximum Weight: " <<express.maxWeight <<  endl;
    cout << " |        Truck Maximum Volume: " <<express.maxVolume << endl;
    cout << " |        Truck Cost: " <<express.cost << " $"<< endl;
}

void thirdScenario__::printOnlyMax( vector<int> bestDelivery) {
    cout << " |-->  Successfully delivered : "<< (double)((double)bestDelivery[1] / (double)requests.size())*100 << "%"<< endl;
    cout << " |-->  Delivery Time : "<< bestDelivery[0] << " s"<< endl;
    cout << "-*----------------------------------------------------*-" << endl;
}

void thirdScenario__::printComputationTime(chrono::duration<double> elapsed_seconds, time_t end_time) {
    cout << "-*-------------  Computation Time --------------------*-" << endl;
    cout << " |--> Time Details: " << endl;
    cout << " |        Elapsed Time: " << elapsed_seconds.count() << "s" << endl;
    cout << " |        Finished Computation At: " << std::ctime(&end_time);
    cout << "-*----------------------------------------------------*-" << endl;
}
