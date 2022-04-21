//
// Created by Eduardo Correia on 09/04/2022.
// Developed by José Carvalho
//

#ifndef DA_T1_THIRDSCENARIO_H
#define DA_T1_THIRDSCENARIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "../abstractAlgorithm.h"

class thirdScenario : abstractAlgorithm{
private:
    /**
   * Request vector which stores the requests that are then sorted to use in the greedy algorithm approach.
   */
    truck express;
    /**
    * Holds the requests for the day
    */
    /**
     * Vector containing all the requests.
     */
    vector<request> requests;
    /**
     * Vector containing the requests to deliver for the day
     */
    vector<request> deliveryList;
    /**
     * Vector containing all the trucks and correspondent information
     */
    vector<truck> trucks;
    /**
     * Time used to deliver all the requests.
     */
    unsigned int usedTime = 0;
    /**
     * Profit
     */
    unsigned int income = 0;
    /**
     * Timeframe for the deliveries.
     */
    const unsigned int timeFrame = 28800;
    /**
     * Number of requests.
     */
    int nReq = 0;
public:
    /**
    * Constructor for the thirdScenario class, receives a request and truck vector that are used to compute the algorithms.
    * @param requests request vector.
    * @param trucks truck vector.
    */
    thirdScenario(const vector<request>& requests, const vector<truck>& trucks);
    /**
   * Used to ask which algorithm the user wants to use. Also handles the overall flow of the class.
   */
    void compute() override;
    /**
   * Given an valid index returns true if it fits the selected truck.
   * @param int request index.
   * @return returns a boolean.
   */
    bool isDeliverable(int i ) const;
    /**
     * Delivers a given request
     * @param request request to deliver
     */
    void deliver(request &request);
    /**
     * Compares the delivery time of two requests
     * @param a request a
     * @param b request b
     * @return returns a boolean. True if a > b.
     */
    static bool lDeliveryTime(const request &a, const request &b);
    /**
     * Prints the Scenario stats.
     */
    void printStats();
    /**
     *  Computed the first algorithmic option.
     */
    void compute1();
    /**
    *  Computed the second algorithmic option.
    */
    void compute2();
    /**
     * Filters the request list removing the requests that does not fit the truck.
     * @return all the requests that fit the truck.
     */
    vector<request> fitsTruck();
    /**
     * Calculates all the subsets of the delivery vector.
     * @param deliveryVector vector storing all the deliveries.
     * @param res current calculated subsets.
     * @param subset calculated subset.
     * @param index current index of the deliveryVector.
     */
    void calculateDeliverySubsets(vector<int> &deliveryVector, vector<vector<int>> &res, vector<int> &subset, int index);
    /**
     *  Calculated all the subsets of the vector.
     * @param deliveryVector Vector storing the deliveries.
     * @return Vector of delivery vectors.
     */
    vector<vector<int>> subsets(vector<int> &deliveryVector);
    /**
     * Filters the subsets removing the ones that exceed the parameters.
     * @param res vector of subsets.
     * @return Filtered vector of subsets.
     */
    vector<vector<int>> analiseRes(const vector<vector<int>> &res) const;
    /**
     * Returns the best options off all the subsets.
     * @param res Filtered vector of subsets.
     * @return A vector containing  the best subset.
     */
    static vector<int> bestOption(vector<vector<int>> &res) ;
    /**
     * Prints the best subset and subsequent status.
     * @param bestDelivery Vector containing the best subset.
     */
    void printOnlyMax(vector<int> bestDelivery);
    /**
  * Prints the time it took to compute the algorithm, along with the time at which the computation finished.
  * @param bestDelivery Vector containing the best subset.
    * @param elapsed_seconds number of seconds the computation took
  * @param end_time end time for the computation.
  */
    static void printComputationTime(chrono::duration<double> elapsed_seconds, time_t end_time);
    /**
     * Prints the truck details.
     */
    void printTruckDetails() const;
    /**
     * Loads the truck information.
     */
    void loadTruck();
};


#endif //DA_T1_THIRDSCENARIO_H
