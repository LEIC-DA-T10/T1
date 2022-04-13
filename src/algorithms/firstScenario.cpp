//
// Created by Eduardo Correia on 09/04/2022.
//


#include "firstScenario.h"
#include <climits>
#include <iostream>

firstScenario::firstScenario(vector<request> requests, vector<truck> trucks) : abstractAlgorithm(requests, trucks) {}

//Todo create first algorithm
//Bin Packing Best-fit Algorithm Implemetation
void firstScenario::compute() {
    //Passar para uma func e mandar o discarted para outro scenario
    vector<request> discarted;
    unsigned int tempWeight, tempVolume, tempTime;
    auto tempVan =trucks.end();

    for (auto item = requests.begin(); item != requests.end(); item++) {
        tempWeight = UINT_MAX;
        tempTime = UINT_MAX;
        tempVolume = UINT_MAX;
        tempVan =trucks.end();

        if(item->duration >= 86400){ //Greater than 24H
            discarted.push_back(*item);
            //requests.erase(item);
        } else{
            for (auto van = trucks.begin(); van != trucks.end(); van++) {
                if(van->truckLoad.empty())
                {
                    //Didnt find any containers where it fits
                    if(tempVan == trucks.end()){
                        //assumir que se tiver vazio cabe
                        van->truckLoad.push_back(*item);
                        van->availableWeight -= item->weight;
                        van->availableTime  -= item->duration;
                        van->availableVolume -= item->volume;
                    } else{
                        tempVan->truckLoad.push_back(*item);
                        tempVan->availableWeight -= item->weight;
                        tempVan->availableTime  -= item->duration;
                        tempVan->availableVolume -= item->volume;
                    }

                    break;
                } else{
                    if(!isNegative(*van, *item)){
                        if(tempWeight >= (van->availableWeight - item->weight)  &&  tempTime >= (van->availableTime - item->duration)  &&  tempVolume >= (van->availableVolume - item->duration)){
                            tempWeight = van->availableWeight - item->weight;
                            tempVolume = van->availableVolume - item->volume;
                            tempTime = van->availableTime - item->duration;
                            tempVan = van; //THIS might be wrong
                        }
                    }
                }
            }
        }
    }
    for(truck van : trucks){
        if(van.truckLoad.size() != 0){
            cout << "van" << van.maxWeight  << "     " << endl;
            truckLoadPrint(van.truckLoad);
            cout << endl;
        } else{
            cout << "no find" << endl;
            truckLoadPrint(discarted);
            break;
        }
    }
}


bool isNegative(truck van, request item){
    return (van.availableWeight < item.weight || van.availableVolume < item.volume || van.availableTime < item.duration);
}

void truckLoadPrint(vector<request> truckLoad){
    int sum = 0;
    for(request load : truckLoad){
        cout << "Duration: "<< load.weight << endl;
        sum += load.weight;
    }
    cout <<"TOTAL "<< sum << endl;
}
