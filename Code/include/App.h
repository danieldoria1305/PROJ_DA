#ifndef PROJETODA_APP_H
#define PROJETODA_APP_H

#include "LoadFiles.h"

class App {
public:
    void start();
    bool printUserMenu();
    void printMaxTrainsBetweenTwoStations();
    void printStationsMostAmountTrains();
    void printTopkMunicipalitiesDistricts();
    void printTrainsTravelMinimumCost();
    void printMaxTrainsReducedConnect();
    void printReportStations();
private:
    LoadFiles loadFiles;
    string type_;
};


#endif //PROJETODA_APP_H
