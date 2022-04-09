//
// Created by Eduardo Correia on 09/04/2022.
//

#ifndef DA_T1_THIRDSCENARIO_H
#define DA_T1_THIRDSCENARIO_H


#include "../abstractAlgorithm.h"

class thirdScenario : abstractAlgorithm{
public:
    thirdScenario(vector<request> requests, vector<truck> trucks);
    void compute() override;
};


#endif //DA_T1_THIRDSCENARIO_H
