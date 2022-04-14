//
// Created by Eduardo Correia on 09/04/2022.
// Developed by José Carvalho
//

#include "thirdScenario.h"

thirdScenario::thirdScenario(const vector<request>& requests1, const vector<truck>& trucks1) : abstractAlgorithm(requests1, trucks1){
    requests = requests1;
    trucks = trucks1;
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
    auto deliPerc = (double)(((double)nReq / (double)requests.size()) * (double)100.0);
    double avgTime = usedTime/nReq;
    int avgTimeM = avgTime/60;
    int avgTimeS = int(avgTime)%60;

    cout << "-*-------------  Report Scenario 3  ------------------*-" << endl;
    cout << " |--> Truck Details: " << endl;
    cout << " |        Truck Maximum Weight: " <<express.maxWeight << "Kg" << endl;
    cout << " |        Truck Maximum Volume: " <<express.maxVolume << "m3" <<endl;
    cout << " |        Truck Cost: " <<express.cost << "$"<< endl;
    cout << " |--> Deliveries: " << endl;

    cout << " |        Delivered: " << deliPerc << "% ("<<nReq<<")"<< endl;

    if (requests.size() - nReq == 0){
        cout << " |        Rejected: 0%" << endl;
    }else
        cout << " |        Rejected: " << 100 - deliPerc << "%" << endl;
    cout << " |        Average Time per Delivery: "<< avgTimeM << "min "<<avgTimeS<<"secs"<<endl;
    cout << " |--> Balance: " << endl;
    cout << " |       Gains from Deliveries: " << income << "$" << endl;
    cout << " |       Total profit: " <<income - express.cost<< "$"<< endl;

    cout << "-*----------------------------------------------------*-" << endl;
    cout << "    Do you want to see the request details? (y/n)" << endl;
    char answer;
    cin >> answer;
    if(answer == 'y'){
        cout << "[Id] [Weight] [Volume] [Reward] [Delivery time]"<< endl;
        for (int i = 0 ; i < deliveryList.size(); i++){
            cout << "[" <<i+1<<"] "<< deliveryList.at(i).weight<<"Kg "<< deliveryList.at(i).volume <<"m3 " << deliveryList.at(i).reward<<"$ "<<deliveryList.at(i).duration <<"s"<< endl;
        }
    }
    cout << "------  End Of Scenario 3  -------"<< endl<< endl<< endl;
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


