//
// Created by danieldoria on 15-03-2023.
//

#ifndef PROJETODA_LOADFILES_H
#define PROJETODA_LOADFILES_H


#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Station.h"
#include "Network.h"
#include "Graph.h"
#include "VertexEdge.h"

using namespace std;

class LoadFiles{

public:
    Graph readStations(); // read the entire stations document

    void loadStations(string str, Graph &StationsGraph); // given a line read in readStations, update the Station vector with a new station

    vector <Station> getStationVector(); // gets the vector created with all the stations

    void readNetwork(); // read the entire Network document

    void loadNetwork (string str); // given a line read in readNetwork, update the Network vector with a new Network

    vector<Network> getNetworkVector(); // gets the vector created with all the Network

private:
    vector<Station> stations; // vector with all stations

    vector<Network> networks; // vector with all network

};

#endif //PROJETODA_LOADFILES_H
