
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
    unsigned int availableWeight;
    unsigned int availableVolume;
    unsigned int availableTime = 86400;
    unsigned int profit;
    std::vector<request> truckLoad;
};

struct loadLessTruck{
    unsigned int maxVolume;
    unsigned int maxWeight;
    unsigned int cost;
    bool used = false;
};

#endif //DA_T1_DATASTRUCTS_H
