//
// Created by Ze Carvalho on 16/04/2022.
//

#include "thirdScenario__.h"

thirdScenario__::thirdScenario__(const vector<request> &requests1, const vector<truck> &trucks1) : abstractAlgorithm(requests1, trucks1) {
    requests = requests1;
    requests = fitsTruck();
    trucks = trucks1;
    if (trucks.size() > 1)
        cout << "---- WARNING : MORE THAN 1 TRUCK PROVIDED ONLY THE FIRST WILL BE CONSIDERED ----" << endl;

}

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

void thirdScenario__::Combination(vector<request> a, int reqLen, int start, int currLen, bool check[], int len){
    int runDuration = 0;
    // Return if the currLen is more than the required length.
    if(currLen > reqLen)
        return;
        // If currLen is equal to required length then print the sequence.
    else if (currLen == reqLen)
    {
        for (int i = 0; i < len; i++)
        {
            if (check[i] == true)
            {
                runDuration+= a.at(i).duration;
            }
        }
    //    if (runDuration <= timeFrame)// cout << runDuration << " " << endl;
        return;
    }
    // If start equals to len then return since no further element left.
    if (start == len)
    {
        return;
    }
    // For every index we have two options.
    // First is, we select it, means put true in check[] and increment currLen and start.
    check[start] = true;
    Combination(a, reqLen, start + 1, currLen + 1, check, len);
    // Second is, we don't select it, means put false in check[] and only start incremented.
    check[start] = false;
    Combination(a, reqLen, start + 1, currLen, check, len);
}

void thirdScenario__::compute() {
    cnt = 0;
    testSomething(requests, 1, 0);
    cout << cnt << endl;
}

void thirdScenario__::testSomething(vector<request> pat, int i, int currSum)
{
    if (currSum == timeFrame)
    {
        cnt++;
        return;
    }

    if (currSum < timeFrame && i < requests.size())
    {
        testSomething(pat, i + 1, currSum + pat[i].duration);
        testSomething(pat, i + 1, currSum);
    }
}


