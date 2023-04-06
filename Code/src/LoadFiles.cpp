//
// Created by danieldoria on 15-03-2023.
//

#include "../include/LoadFiles.h"
#include "../include/VertexEdge.h"
#include "../include/Graph.h"
Graph StationsGraph;

vector <Station> stations;

void LoadFiles::readStations (){
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
            loadStations(line);
        }
        jump=1;
    }

    stationsFile.close();

}

void LoadFiles::loadStations(string str) {
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

void LoadFiles::loadNetwork(string str) {
    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }

    Network aux (result[0], result[1], stoi(result[2]), result[3]);


    for (auto e: getNetworkVector()){
        if (aux.getCapacity()==e.getCapacity() && aux.getStationB()==e.getStationB() && aux.getStationA()==e.getStationA() && aux.getService()==e.getService()){
            return;
        }
    }

    networks.push_back(aux);
}


void LoadFiles::createAdjs(){
    vector<Network> networks = getNetworkVector();

    for (auto a:networks){
        StationsGraph.findVertex(a.getStationA())->addEdge(StationsGraph.findVertex(a.getStationA()), StationsGraph.findVertex(a.getStationB()), a.getCapacity(), a.getService());
        StationsGraph.findVertex(a.getStationB())->addEdge(StationsGraph.findVertex(a.getStationB()), StationsGraph.findVertex(a.getStationA()), a.getCapacity(), a.getService());
    }
}

vector<Network> LoadFiles::getNetworkVector() {
    return networks;
}

Graph LoadFiles::getGraph() {
    return StationsGraph;
}
