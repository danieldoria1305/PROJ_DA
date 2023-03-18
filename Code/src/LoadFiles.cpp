//
// Created by danieldoria on 15-03-2023.
//

#include "../include/LoadFiles.h"

void LoadFiles::readStations (){
    string stationsFilePath = "dataset/stations.csv";
    fstream stationsFile;
    stationsFile.open(stationsFilePath);
    int jump =0;

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
    stations.push_back(aux);
}

vector<Station> LoadFiles::getStationVector() {
    return stations;
}

void LoadFiles::readNetwork() {
    string networkFilePath = "dataset/network.csv";
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
    networks.push_back(aux);
}

vector<Network> LoadFiles::getNetworkVector() {
    return networks;
}


