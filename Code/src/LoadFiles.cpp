//
// Created by danieldoria on 15-03-2023.
//

#include "../include/LoadFiles.h"

void loadStations (){
    string stationsFilePath = "../Code/dataset/stations.csv";
    fstream stationsFile;
    stationsFile.open(stationsFilePath);

    if (stationsFile.fail()) {
        cerr << "Unable to open " << stationsFilePath << endl;
    }

    string throwAwayString;
    getline(stationsFile, throwAwayString);

    while (stationsFile.peek() != EOF) {
        string line;
        vector<string> strings;
        getline(stationsFile, line);
        customSplit(line, ',', strings);
        Station newStation = Station(strings[0], strings[1], strings[2],
                                     strings[3], strings[4]);

        stations.emplace(strings[0], newStation);
        stationsGraph.insertStation(strings[0]);
        ??? cities.emplace(strings[2]);
        countries.emplace(strings[3]);
    }
}

void loadNetworks ({})