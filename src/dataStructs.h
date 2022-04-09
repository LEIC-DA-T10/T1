
#ifndef DA_T1_DATASTRUCTS_H
#define DA_T1_DATASTRUCTS_H

#include <vector>

struct request{
    unsigned int weight;
    unsigned int volume;
    unsigned int reward;
    unsigned int duration;
};

struct truck{
    unsigned int maxVolume;
    unsigned int maxWeight;
    unsigned int cost;
    std::vector<request> truckLoad;
};

#endif //DA_T1_DATASTRUCTS_H
