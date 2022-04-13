//
// Created by Eduardo Correia on 09/04/2022.
//

#ifndef DA_T1_FIRSTSCENARIO_H
#define DA_T1_FIRSTSCENARIO_H


#include "../abstractAlgorithm.h"

class firstScenario : abstractAlgorithm{
public:
    firstScenario(vector<request> requests, vector<truck> trucks);
    void compute() override;

};

bool isNegative(unsigned int first, unsigned int second);
void truckLoadPrint(vector<request> truckLoad);
#endif //DA_T1_FIRSTSCENARIO_H
