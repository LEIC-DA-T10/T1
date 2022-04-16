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

    int nReq = 0;

    int cnt;

public:
    thirdScenario__(const vector<request>& requests, const vector<truck>& trucks);
    void compute() override;

    vector<request> fitsTruck();
    bool isDeliverable(int i) const;




    void Combination(vector<request> a, int reqLen, int start, int currLen, bool *check, int len);

    void testSomething(vector<request> pat, int i, int currSum);
};
#endif //DA_T1_THIRDSCENARIO___H
