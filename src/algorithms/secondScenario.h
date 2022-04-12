//
// Created by dudud on 09/04/2022.
//

#ifndef DA_T1_SECONDSCENARIO_H
#define DA_T1_SECONDSCENARIO_H


#include "../abstractAlgorithm.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <chrono>

class secondScenario : abstractAlgorithm{
private:
    vector<request> sortedRequests;
    vector<truck> sortedTrucks;
    vector<truck> outputTrucks[3];
    int bestScenario;
    static bool truckWeightToCost(const truck &a, const truck &b);
    static bool requestWeightToReward(const request &a, const request &b);
    static bool truckVolumeToCost(const truck &a, const truck &b);
    static bool requestVolumeToReward(const request &a, const request &b);
    static bool wvRatioToCost(const truck &a, const truck &b);
    static bool wvRatioToReward(const request &a, const request &b);
    static void printTrucks(const vector<truck> &trucks);
    static void printRequests(const vector<request> &requests);
    unsigned int computeByWeight();
    unsigned int computeByVolume();
    unsigned int computeByWeightToVolume();
    static bool checkAndInsert(request requestToInsert, truck &truckToInsert);
    static int calculateProfit(vector<truck> &trucks);
    unsigned int getMax3(unsigned int value1,unsigned int value2,unsigned int value3);
    static unsigned int calculateCost(const vector<truck> &trucks);
    static unsigned int numberOfRequests(const vector<truck> &trucks);
    void printResult(unsigned int);
    static void printComputationTime(chrono::duration<double> elapsed_seconds,time_t end_time);
public:
    secondScenario(const vector<request>& requests, const vector<truck>& trucks);
    void compute() override;



};


#endif //DA_T1_SECONDSCENARIO_H
