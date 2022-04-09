
#include <gtest/gtest.h>
#include "dataIO.h"
#include "applicationController.h"

#define TRUCK_PATH "../data/input/carrinhas.txt"
#define REQUEST_PATH "../data/input/encomendas.txt"

using namespace std;

void printMainMenu(){
    cout << "Choose an option -->" << endl;
    cout << "---- Choosing Input ----" << endl;
    cout << "1 - Fixed input from dataset from position n to position m" << endl;
    cout << "2 - Random input from dataset" << endl;
    cout << "---- Computing Scenarios ----" << endl;
    cout << "3 - Compute Scenario 1" << endl;
    cout << "4 - Compute Scenario 2" << endl;
    cout << "5 - Compute Scenario 3" << endl;
    cout << "---- Configuration ----" << endl;
    cout << "6 - Export output to file ? (default = no) (y/s)";
}


int main(){
    dataIO data(TRUCK_PATH, REQUEST_PATH);
    applicationController controller;
    int state;
    while(true){
        printMainMenu();
        controller.run();
    }
    return 0;
}
