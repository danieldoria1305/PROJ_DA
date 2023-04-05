//
// Created by danieldoria on 03-04-2023.
//

#ifndef PROJETODA_APP_H
#define PROJETODA_APP_H

#include "LoadFiles.h"

class App {
public:
    void start();
    bool printUserMenu();
/*    void printMaxTrainsBetweenTwoStation();
    void printStationsMostAmountTrains();
    void printTopkMunicipalitiesDistricts();
    void printMaxTrainsArriveSimul();
    void printTrainsTravelMinimumCost();
    void printMaxTrainsReducedConnect();
    void printPreferences();*/
private:
    LoadFiles loadFiles;
    //set<string> stations_;
    //string type_;
};


#endif //PROJETODA_APP_H
