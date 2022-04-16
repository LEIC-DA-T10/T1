//
// Created by Ze Carvalho on 16/04/2022.
//

#ifndef DA_T1_THIRDSCENARIO___H
#define DA_T1_THIRDSCENARIO___H
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "../abstractAlgorithm.h"

class thirdScenario__ : abstractAlgorithm{
private:
    truck express;
    vector<request> requests;
    vector<truck> trucks;

    unsigned int usedTime = 0;
    const unsigned int timeFrame = 28800;
public:
    thirdScenario__(const vector<request>& requests, const vector<truck>& trucks);
    void compute() override;

    vector<request> fitsTruck();
    bool isDeliverable(int i) const;

    void calculateDeliverySubsets(vector<int> &deliveryVector, vector<vector<int>> &res, vector<int> &subset, int index);
    vector<vector<int>> subsets(vector<int> &deliveryVector);
    vector<vector<int>> analiseRes(const vector<vector<int>> &res) const;

    static vector<int> bestOption(vector<vector<int>> &res) ;

    static void printOnlyMax(unsigned int maximum);

    static void printComputationTime(chrono::duration<double> elapsed_seconds, time_t end_time);

    void printTruckDetails() const;

    void printOnlyMax(vector<int> bestDelivery);
};
#endif //DA_T1_THIRDSCENARIO___H
