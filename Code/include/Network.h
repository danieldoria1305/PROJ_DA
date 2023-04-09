//
// Created by danieldoria on 15-03-2023.
//

#ifndef PROJETODA_NETWORK_H
#define PROJETODA_NETWORK_H

#include <string>

using namespace std;

class Network {
public:
    Network(string station_a, string station_b, int capacity, string service); // Constructor
    Network(); // Default constructor
    string getStationA() const; // Returns the name of station A
    string getStationB() const; // Returns the name of station B
    int getCapacity() const; // Returns the capacity of the network
    string getService() const; // Returns the type of service provided

private:
    string station_a_; // Name of station A
    string station_b_; // Name of station B
    int capacity_; // Capacity of the network
    string service_; // Type of service
};


#endif //PROJETODA_NETWORK_H
