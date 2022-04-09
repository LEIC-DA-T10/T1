//
// Created by dudud on 09/04/2022.
//

#include "applicationController.h"

using namespace std;

applicationController::applicationController() {
    state = 0;
    exportToFile = false;
}

bool applicationController::run() {
    switch (state) {
        case 1:
            readFixed();
            return true;
        case 2:
            readRandom();
            return true;
        case 3:
            computeFirst();
            return true;
        case 4:
            computeSecond();
            return true;
        case 5:
            computeThird();
            return true;
        case 6:
            changeExportConfig();
            return true;
        default:
            return false;
    }
}

void applicationController::setState(int new_state) {
    this->state = new_state;
}

void applicationController::readFixed() {
    int startingIndex, endingIndex;
    data.checkNumberRequests();
    data.checkNumberTrucks();
    cout << "---- Truck Dataset ----" << endl;
    cout << "Starting Index [0,"<< data.getNumberTrucks() <<"] : " << endl;
    cin >> startingIndex;
    cout << "Ending Index [" << startingIndex << "," << data.getNumberTrucks() <<"] : " << endl;
    cin >> endingIndex;
    data.readTrucksFixed(startingIndex,endingIndex);

    cout << "---- Request Dataset ----" << endl;
    cout << "Starting Index [0,"<< data.getNumberRequests() <<"] : " << endl;
    cin >> startingIndex;
    cout << "Ending Index [" << startingIndex << "," << data.getNumberRequests() <<"] : " << endl;
    cin >> endingIndex;
    data.readRequestsFixed(startingIndex,endingIndex);
}

void applicationController::readRandom() {

}

void applicationController::computeFirst() {

}

void applicationController::computeSecond() {

}

void applicationController::computeThird() {

}

void applicationController::changeExportConfig() {

}




