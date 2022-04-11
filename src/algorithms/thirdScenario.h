//
// Created by Eduardo Correia on 09/04/2022.
// Developed by José Carvalho
//

#ifndef DA_T1_THIRDSCENARIO_H
#define DA_T1_THIRDSCENARIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "../abstractAlgorithm.h"

class thirdScenario : abstractAlgorithm{
private:
    truck express;
    vector<request> requests;
    vector<truck> trucks;


    unsigned int usedTime = 0;
    unsigned int income = 0;
    const unsigned int timeFrame = 28800;
    int nReq = 0;
    vector<request> deliveryList;

public:
    thirdScenario(const vector<request>& requests, const vector<truck>& trucks);
    void compute() override;
    bool isDeliverable(int i ) const;
    void deliver(request &request);
    static bool lDeliveryTime(const request &a, const request &b);
    void printStats();
};


#endif //DA_T1_THIRDSCENARIO_H
