//
// Created by dudud on 09/04/2022.
//

#define TRUCK_PATH "../data/input/carrinhas.txt"
#define REQUEST_PATH "../data/input/encomendas.txt"


#ifndef DA_T1_APPLICATIONCONTROLLER_H
#define DA_T1_APPLICATIONCONTROLLER_H
#include "dataIO.h"
#include <cstdlib>


class applicationController {
private:
    unsigned int state;
    dataIO data = dataIO(TRUCK_PATH, REQUEST_PATH);
    bool exportToFile;
    void readFixed();
    void readRandom();
    void computeFirst();
    void computeSecond();
    void computeThird();
    void changeExportConfig();
public:
    applicationController();
    bool run();
    void setState(int state);
};


#endif //DA_T1_APPLICATIONCONTROLLER_H
