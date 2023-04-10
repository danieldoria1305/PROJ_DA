//
// Created by danieldoria on 03-04-2023.
//


#include "../include/App.h"
#include "../include/Functions.h"
#include <iostream>
#include <string>

using namespace std;

void App::start() {
    loadFiles.readStations();
    loadFiles.readNetwork();
    loadFiles.createAdjs();

    Graph g = loadFiles.getGraph();

    while(true) {
        if (!printUserMenu()) {
            break;
        }
    }
}

bool App::printUserMenu() {
    cout << "╒══════════════════════════════════════════════════╤═════════════════════════════════════════════╕\n"
            "│                   Basic Service                  │  Operation Cost Optimization & Reliability  │\n"
            "│                      Metrics                     │      and Sensitivity to Line Failures       │\n"
            "╞══════════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
            "│                                                  │                                             │\n"
            "│   Maximum number of trains that can travel  [11] │   Maximum number of trains that can    [21] │\n"
            "│ simultaneously between two stations              │ travel between two specific stations        │\n"
            "│                                                  │ with minimum cost for the company           │\n"
            "│   Which stations require the most amount    [12] │                                             │\n"
            "│ of trains to when taking full advantage of       │   Maximum number of trains that can    [22] │\n"
            "│ the existing network capacity                    │ travel between two specific stations        │\n"
            "│                                                  │ in a network of reduced connectivity        │\n"
            "│   Top-k municipalities and districts        [13] │                                             │\n"
            "| regarding their transportation needs             |   Report on the stations  that are the [23] |\n"
            "│                                                  │ most affected by each segment failure       │\n"
            "│                                                  │                                             │\n"
            "╞══════════════════════════════════════════════════╧═════════════════════════════════════════════│\n"
            "│                                          Other operations                                      │\n"
            "╞════════════════════════════════════════════════════════════════════════════════════════════════╡\n"
            "│  Exit                                                                                     [41] │\n"
            "╘════════════════════════════════════════════════════════════════════════════════════════════════╛\n"
            "                                                                                                  \n";
    string operation;
    cin >> operation;
    cin.ignore();
   try {
       switch (stoi(operation)) {
            case 11: {
                printMaxTrainsBetweenTwoStations();
                break;
            }
            case 12:
                printStationsMostAmountTrains();
                break;
            case 13:
                printTopkMunicipalitiesDistricts();
                break;
            case 21:
                printTrainsTravelMinimumCost();
                break;
            case 22:
                printMaxTrainsReducedConnect();
                break;
            case 23:
                printReportStations();
                break;
            case 41:
                return false;
            default:
                cout << "Invalid Operation..." << endl;
        }
    }catch(std::invalid_argument){
        cout << "Invalid Operation..." << endl;
    }

    return true;
}

void App::printMaxTrainsBetweenTwoStations() {
    string station1, station2;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│               1º Station Name               │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the station name to see the maximum  │\n"
             "│ number of trains                            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,station1);

    if (station1 == "1") return;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│               2º Station Name               │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the station name to see the maximum  │\n"
             "│ number of trains                            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";

    getline(cin,station2);

    if (station2 == "1") return;

    cout << "╒═════════════════════════════════════════════╕\n"
            "     The number of trains that can travel      \n";
    cout << "  simultaneously between " << station1 << "\n";
    cout << "  and " << station2 << " is: " << maxNumTrainsTwoStations(station1, station2) << "\n";
    cout << "╞═════════════════════════════════════════════╡\n"
            "│  Press enter to return                      │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    cin.ignore();
}

void App::printStationsMostAmountTrains() {
    vector<pair<string, string>> aux = maxMAxFlow();

    cout <<  "╒══════════════════════════════════════════════╕\n"
             "│               Pairs of Stations              │\n"
             "╞══════════════════════════════════════════════╡\n";

    for(auto a: aux){
        cout << "    " << a.first << " │ " << a.second << "\n";
        cout <<  "╞══════════════════════════════════════════════╡\n";
    }
    cout << "│  Press enter to return                       │\n"
            "╘══════════════════════════════════════════════╛\n"
            "                                               \n";
    cin.ignore();
}

void App::printTopkMunicipalitiesDistricts() {
    string option;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│               Choose an option              │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Municipalities                       [11]  │\n"
             "│  Districts                            [22]  │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    cin >> option;
    switch(stoi(option)) {
        case 11: {
            string k;
            cout <<  "╒═════════════════════════════════════════════╕\n"
                     "│                  Value of k                 │\n"
                     "╞═════════════════════════════════════════════╡\n"
                     "│  Write down a value for the k. This value   │\n"
                     "│ must be an integer between 1 and 278        │\n"
                     "╞═════════════════════════════════════════════╡\n"
                     "│  Return                                [E]  │\n"
                     "╘═════════════════════════════════════════════╛\n"
                     "                                               \n";
            cin >> k;
            if(k == "E") return;
            else if (stoi(k) < 1 || stoi(k) > 278) {
                cout << "Invalid Operation..." << endl;
                return;
            }
            else if (stoi(k) >= 1 && stoi(k) <= 278) {
                vector<pair<string, int>> aux = maxFlowMunicipality(int(stoi(k)));
                cout << "╒═════════════════════════════════════════════╕\n"
                        "│            Top-k Municipalities             │\n"
                        "╞═════════════════════════════════════════════╡\n";

                for (auto a: aux) {
                    cout << "    " << a.first << " │ " << a.second << "\n";
                    cout << "╞═════════════════════════════════════════════╡\n";
                }
                cout << "│  Press enter to return                      │\n"
                        "╘═════════════════════════════════════════════╛\n"
                        "                                               \n";
                cin.ignore();
            }
            else {
                cout << "Invalid Operation..." << endl;
                return;
            }
            break;
        }
        case 22: {
            string k;
            cout <<  "╒═════════════════════════════════════════════╕\n"
                     "│                  Value of k                 │\n"
                     "╞═════════════════════════════════════════════╡\n"
                     "│  Write down a value for the k. This value   │\n"
                     "│ must be an integer between 1 and 18         │\n"
                     "╞═════════════════════════════════════════════╡\n"
                     "│  Return                                [E]  │\n"
                     "╘═════════════════════════════════════════════╛\n"
                     "                                               \n";
            cin >> k;
            if(k == "E") return;
            else if (stoi(k) < 1 || stoi(k) > 18) {
                cout << "Invalid Operation..." << endl;
                return;
            }
            else if (stoi(k) >= 1 && stoi(k) <= 18) {
                vector<pair<string, int>> aux = maxFlowDistrict(int(stoi(k)));
                cout << "╒═════════════════════════════════════════════╕\n"
                        "│                Top-k Districts              │\n"
                        "╞═════════════════════════════════════════════╡\n";

                for (auto a: aux) {
                    cout << "    " << a.first << " │ " << a.second << "\n";
                    cout << "╞═════════════════════════════════════════════╡\n";
                }
                cout << "│  Press enter to return                      │\n"
                        "╘═════════════════════════════════════════════╛\n"
                        "                                               \n";
                cin.ignore();
            }
            else {
                cout << "Invalid Operation..." << endl;
                return;
            }
            break;
        }
        case 1: {
            return;
        }
        default: {
            cout << "Invalid Operation..." << endl;
        }
    }
}

void App::printTrainsTravelMinimumCost() {
    string source, destination;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│             Source Station Name             │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the source station name              │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,source);
    if(source == "1") return;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│         Destination Station Name            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the destination station name         │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,destination);
    if(destination == "1") return;
    leastCostPathAndMaxFlow(source, destination);
}

void App::printMaxTrainsReducedConnect() {
    string staA, staB, staC, staD;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│             1º Station to Remove            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the station name                     │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,staA);
    if(staA == "1") return;
    cout <<  "\n╒═════════════════════════════════════════════╕\n"
             "│             2º Station to Remove            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the station name                     │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,staB);
    if(staB == "1") return;
    cout <<  "\n╒═════════════════════════════════════════════╕\n"
             "│             Origin Station Name             │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the origin station name              │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,staC);
    if(staC == "1") return;
    cout <<  "\n╒═════════════════════════════════════════════╕\n"
             "│         Destination Station Name            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the destination station name         │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,staD);
    if(staD == "1") return;

    if(maxNumReducedConnectivity(staA, staB, staC, staD) == -1) {
        cout << "╒═══════════════════════════════════════════════════════╕\n"
                "  The connection you want to remove does not exist.\n"
                "╘═══════════════════════════════════════════════════════╛\n"
                "                                                         \n";
    }
    else {
        cout << "╒═══════════════════════════════════════════════════════╕\n"
                "  The max flow between Origin and Destination is: "<< maxNumReducedConnectivity(staA, staB, staC, staD) << "\n"
             "╘═══════════════════════════════════════════════════════╛\n"
             "                                                      \n";
    }
}

void App::printReportStations() {
    string staA, staB, staC, staD;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│             1º Station to Remove            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the station name                     │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,staA);
    if(staA == "1") return;
    cout <<  "\n╒═════════════════════════════════════════════╕\n"
             "│             2º Station to Remove            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the station name                     │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,staB);
    if(staB == "1") return;
    cout <<  "\n╒═════════════════════════════════════════════╕\n"
             "│             Origin Station Name             │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the origin station name              │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,staC);
    if(staC == "1") return;
    cout <<  "\n╒═════════════════════════════════════════════╕\n"
             "│         Destination Station Name            │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the destination station name         │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    getline(cin,staD);
    if(staD == "1") return;

    report(staA, staB, staC, staD);
}