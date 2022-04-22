//
// Created by Eduardo Correia on 09/04/2022.
//

#ifndef DA_T1_FIRSTSCENARIO_H
#define DA_T1_FIRSTSCENARIO_H


#include "../abstractAlgorithm.h"

class firstScenario : abstractAlgorithm{
public:
    /**
     * Constructor for the firstScenario class, receives a request and truck vector that are used to compute the algorithms.
     * @param requests request vector.
     * @param trucks truck vector.
     * @return firstScenario Object
     */
    firstScenario(vector<request> requests, vector<truck> trucks);
    /**
     * function called by invoker to compute first scenario, this is the function that calls all others to compute the program according to what the user requests.
     * the result of this function will be present in the vector params passed to the constructor
     */
    void compute() override;
    /**
    * Function that applies the best fit bin packing algorithm to the truckload of each truck in the vector
    * @param vector of sorted trucks according to the choice made by the user in compute
    * @return vector with only the trucks that are used to distribute the requests
 */
    vector<truck> execute(vector<truck> trucks);
    /**
    * Function that clears the truckload of the trucks in param
    * @param vector of trucks to be cleared
    * @return param is empty after procedure
 */
    void clearTruckLoad(vector<truck> *trucks);
    /**
    * Function that using sort from algorithm sorts the trucks and requests by weight
     * The class objects get sorted
 */
    void computeWeightSort();
    /**
        * Function that using sort from algorithm sorts the class objects trucks and requests by volume
    */
    void computeVolumeSort();
    /**
    * Function that using sort from algorithm sorts the class objects trucks and requests by time
    */
    void computeTimeSort();

};
/**
    * Function that defines how to sort to be used in algorithm sort
    * @param request a to compare to b
    * @param request b to be compared to a
    * @return boolean to say if comparison is true or false
 */
bool requestTimeSort(const request &a, const request &b);
/**
    * Function that defines how to sort to be used in algorithm sort
    * @param truck a to compare to b
    * @param truck b to be compared to a
    * @return boolean to say if comparison is true or false
 */
bool truckWeightSort(const truck &a, const truck &b);
/**
    * Function that defines how to sort to be used in algorithm sort
    * @param request a to compare to b
    * @param request b to be compared to a
    * @return boolean to say if comparison is true or false
 */
bool requestWeightSort(const request &a, const request &b);
/**
    * Function that defines how to sort to be used in algorithm sort
    * @param truck a to compare to b
    * @param truck b to be compared to a
    * @return boolean to say if comparison is true or false
 */
bool truckVolumeSort(const truck &a, const truck &b);
/**
    * Function that defines how to sort to be used in algorithm sort
    * @param request a to compare to b
    * @param request b to be compared to a
    * @return boolean to say if comparison is true or false
 */
bool requestVolumeSort(const request &a, const request &b);
/**
 * Function that returns true if request does not fit in the truck according to restriction (24h, overweight, overvolumed)
 * @param request to be put in truck
 * @param truck to check if request fits with the already existing truckload
 * @return returns true if request does not fit , and false if it fits
 */
bool isNegative(truck, request);

/**
    * Function that prints the result of the execute
    * @param truckLoad to be printed
 */
void truckLoadPrint(vector<request> truckLoad);
/**
    * Function that prints an additional menu so the user picks the way to sort the trucks and requests
    * @return returns the choice the user made
 */
int printMenu();

#endif //DA_T1_FIRSTSCENARIO_H
