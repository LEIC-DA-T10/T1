//
// Created by Eduardo Correia on 09/04/2022.
// Developed by José Carvalho
//

#include "thirdScenario.h"

thirdScenario::thirdScenario(vector<request> requests, vector<truck> trucks) : abstractAlgorithm(requests, trucks){
    if (trucks.size() > 1)
        cout << "---- WARNING : MORE THAN 1 TRUCK PROVIDED ONLY THE FIRST WILL BE CONSIDERED ----" << endl;

    std::sort(requests.begin(), requests.end(), lDeliveryTime);
    express.maxVolume = trucks.at(0).maxVolume;
    express.maxWeight = trucks.at(0).maxWeight;
    express.cost = trucks.at(0).cost;
}


void thirdScenario::compute() {
    for (int i = 0; i < requests.size();i++)
        if (isDeliverable(i))deliver(requests.at(i));

    printStats();
}

void thirdScenario::printStats(){
    cout << "-*----------------------------------------------------*-" << endl;
    cout << " |--> Truck Details: " << endl;
    cout << " |        Truck Maximum Weight " <<express.maxWeight << "Kg" << endl;
    cout << " |        Truck Maximum Volume " <<express.maxVolume << "m3" <<endl;
    cout << " |        Truck Cost " <<express.cost << "$"<< endl;
    cout << " |--> Deliveries : " << endl;
    cout << " |        Delivered " << nReq << " request(s)            " << endl;
    if (requests.size() - nReq == 0){
        cout << " |        Rejected none" << endl;
    }else
        cout << " |        Rejected " << requests.size() - nReq << " request(s)" << endl;
    cout << " |--> Balance: " << endl;
    cout << " |       Gains from Deliveries: " << income << "$" << endl;
    cout << " |       Total profit " <<income - express.cost<< "$"<< endl;
    cout << "-*----------------------------------------------------*-" << endl;
    cout << "    Do you want to see the request details? (y/n)" << endl;
    char answer;
    cin >> answer;
    if(answer == 'y')
        for (int i = 0 ; i < deliveryList.size(); i++)
            cout << "[" <<i+1<<"] "<< deliveryList.at(i).weight<<"Kg "<< deliveryList.at(i).volume <<"m3 " << deliveryList.at(i).reward<<"$ "<<deliveryList.at(i).duration <<" s"<< endl;



}

bool thirdScenario::lDeliveryTime(const request &a, const request &b) {
    return  a.duration < b.duration;}

bool thirdScenario::isDeliverable(int i) const {
    auto request = requests.at(i);
    if (express.maxVolume > request.volume && express.maxWeight > request.weight && request.duration + usedTime <= timeFrame) return true;
    return false;
}

void thirdScenario::deliver(request &request) {
    usedTime += request.duration;
    income += request.reward;
    nReq ++;
    deliveryList.push_back(request);
}


