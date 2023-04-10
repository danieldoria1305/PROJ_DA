#include "../include/Network.h"

Network::Network(string station_a, string station_b, int capacity, string service) {
    station_a_=station_a;
    station_b_=station_b;
    capacity_=capacity;
    service_=service;
}

string Network::getStationA() const {
    return station_a_;
}

string Network::getStationB() const {
    return station_b_;
}

int Network::getCapacity() const {
    return capacity_;
}

string Network::getService() const {
    return service_;
}
