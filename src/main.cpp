
#include <gtest/gtest.h>
#include "dataIO.h"

#define TRUCK_PATH "../data/input/carrinhas.txt"
#define REQUEST_PATH "../data/input/encomendas.txt"

int main(){
    dataIO data(TRUCK_PATH, REQUEST_PATH);

    data.readTrucksRandom(1);
    data.readRequestsRandom(1);
    data.printTrucks();
    data.printRequests();


    return 0;
}
