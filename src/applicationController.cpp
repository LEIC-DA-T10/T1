//
// Created by dudud on 09/04/2022.
//

#include <cstdlib>
#include "applicationController.h"

applicationController::applicationController() {
    state = 0;
}

void applicationController::run() {
    switch (state) {
        case 0:
            printMainMenu();
            break;
        case 1:
            printReadingData();
            break;
        default:
            exit(0);
    }
}

void applicationController::setState(int state) {
    this->state = state;
}
