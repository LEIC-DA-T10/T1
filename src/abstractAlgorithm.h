//
// Created by Eduardo Correia on 09/04/2022.
//

#ifndef DA_T1_ABSTRACTALGORITHM_H
#define DA_T1_ABSTRACTALGORITHM_H


#include "dataStructs.h"

using namespace std;

class abstractAlgorithm {
protected:
    vector<request> requests;
    vector<truck> trucks;
public:
    abstractAlgorithm(const vector<request>& requests,const vector<truck>& trucks);
    virtual void compute() = 0;
};


#endif //DA_T1_ABSTRACTALGORITHM_H
