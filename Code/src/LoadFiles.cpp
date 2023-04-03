//
// Created by danieldoria on 15-03-2023.
//

#include "../include/LoadFiles.h"
#include "../include/VertexEdge.h"
#include "../include/Graph.h"
Graph StationsGraph;


Graph LoadFiles::readStations (){
    string stationsFilePath = "../Code/dataset/stations.csv";
    fstream stationsFile;
    int jump =0;
    stationsFile.open(stationsFilePath);

    if (stationsFile.fail()) {
        cerr << "Unable to open " << stationsFilePath << endl;
    }


    while (stationsFile.peek() != EOF) {
        string line;
        vector<string> strings;
        getline(stationsFile, line);
        if (jump==1) {
            loadStations(line, StationsGraph);
        }
        jump=1;
    }

    stationsFile.close();

    return StationsGraph;
}

void LoadFiles::loadStations(string str, Graph &StationsGraph) {
    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }

    Station aux (result[0], result[1], result[2], result[3], result[4]);

    for (auto e: getStationVector()){
        if (aux.getMunicipality()==e.getMunicipality() && aux.getDistrict()==e.getDistrict() && aux.getName()==e.getName() && aux.getLine()==e.getLine() && aux.getTownship()==e.getTownship()){
            return;
        }
    }

    StationsGraph.addVertex(aux.getName());
    stations.push_back(aux);
}

vector<Station> LoadFiles::getStationVector() {
    return stations;
}

void LoadFiles::readNetwork() {
    string networkFilePath = "../Code/dataset/network.csv";
    fstream networkFile;
    networkFile.open(networkFilePath);
    int jump =0;

    if (networkFile.fail()) {
        cerr << "Unable to open " << networkFilePath << endl;
    }



    while (networkFile.peek() != EOF) {
        string line;
        vector<string> strings;
        getline(networkFile, line);
        if (jump==1) {
            loadNetwork(line);
        }
        jump=1;
    }

    networkFile.close();

}

void LoadFiles::loadNetwork(string str, Graph &Stationsgraph) {
    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }



    Network aux (result[0], result[1], stoi(result[2]), result[3]);

    Vertex* a(aux.getStationA());
    Vertex* b(aux.getStationB());


    Edge edge (a, b, stoi(result[2]), result[3]);

    for (auto e: getNetworkVector()){
        if (aux.getCapacity()==e.getCapacity() && aux.getStationB()==e.getStationB() && aux.getStationA()==e.getStationA() && aux.getService()==e.getService()){
            return;
        }
    }

    Graph::findVertex(aux.getStationA())->addAdj(aux);
    networks.push_back(aux);
}

vector<Network> LoadFiles::getNetworkVector() {
    return networks;
}


