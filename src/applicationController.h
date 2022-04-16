//
// Created by Eduardo Correia on 09/04/2022.
//


#define TRUCK_PATH "../data/input/carrinhas.txt"
#define REQUEST_PATH "../data/input/encomendas.txt"



#ifndef DA_T1_APPLICATIONCONTROLLER_H
#define DA_T1_APPLICATIONCONTROLLER_H
#include "dataIO.h"
#include <cstdlib>
#include "algorithms/firstScenario.h"
#include "algorithms/secondScenario.h"
#include "algorithms/thirdScenario.h"



class applicationController {
private:
    unsigned int state;
    dataIO data = dataIO(TRUCK_PATH, REQUEST_PATH);
    void readFixed();
    void readRandom();
    void computeFirst();
    void computeSecond();
    void computeThird();
    void printTruck();
    void printRequest();
    static bool checkForEmpty(const std::vector<request> &vector);
    static bool checkForEmpty(const std::vector<truck> &vector);
public:
    applicationController();
    bool run();
    void setState(int state);
    static void printMainMenu();

    void computeThird_();
};


#endif //DA_T1_APPLICATIONCONTROLLER_H
