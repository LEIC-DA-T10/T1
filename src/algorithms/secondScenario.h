//
// Created by dudud on 09/04/2022.
//

#ifndef DA_T1_SECONDSCENARIO_H
#define DA_T1_SECONDSCENARIO_H


#include "../abstractAlgorithm.h"

class secondScenario : abstractAlgorithm{
private:
    vector<request> sortedRequests;
    vector<truck> sortedTrucks;
    vector<truck> weightOutput;
    vector<truck> volumeOutput;
    vector<truck> weightToVolumeOutput;
    static bool truckWeightToCost(const truck &a, const truck &b);
    static bool requestWeightToReward(const request &a, const request &b);
    static bool truckVolumeToCost(const truck &a, const truck &b);
    static bool requestVolumeToReward(const request &a, const request &b);
    static void printTrucks(const vector<truck> &trucks);
    static void printRequests(const vector<request> &requests);
    int computeByWeight();
    unsigned int computeByVolume();
    unsigned int computeByWeightToVolume();
    static bool checkAndInsert(request requestToInsert, truck &truckToInsert);
    static int calculateProfit(vector<truck> &trucks);
public:
    secondScenario(const vector<request>& requests, const vector<truck>& trucks);
    void compute() override;
};


#endif //DA_T1_SECONDSCENARIO_H
