
#include <gtest/gtest.h>
#include "dataIO.h"

#define TRUCK_PATH "../data/input/carrinhas.txt"
#define REQUEST_PATH "../data/input/encomendas.txt"

int main(){
    dataIO data(TRUCK_PATH, REQUEST_PATH);
    data.readRequestsFixed(0, 10);
    data.readTrucksFixed(0,10);
    data.printRequests();
    data.printTrucks();

    return 0;
}
