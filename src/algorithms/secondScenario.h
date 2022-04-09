//
// Created by dudud on 09/04/2022.
//

#ifndef DA_T1_SECONDSCENARIO_H
#define DA_T1_SECONDSCENARIO_H


#include "../abstractAlgorithm.h"

class secondScenario : abstractAlgorithm{
public:
    secondScenario(vector<request> requests, vector<truck> trucks);
    void compute() override;
};


#endif //DA_T1_SECONDSCENARIO_H
