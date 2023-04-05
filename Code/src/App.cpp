//
// Created by danieldoria on 03-04-2023.
//

#include "../include/App.h"

using namespace std;

void App::start() {
    loadFiles.readStations();
    loadFiles.readNetwork();
    while(true) {
        if (!printUserMenu()) {
            break;
        }
    }
}

bool App::printUserMenu() {
    cout << "╒══════════════════════════════════════════════════╤═════════════════════════════════════════════╕\n"
            "│                   Basic Service                  │  Operation Cost Optimization & Reliability  │\n" // Titulos das tabelas temporários, ainda se vai alterar isto
            "│                      Metrics                     │      and Sensitivity to Line Failures       │\n"
            "╞══════════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
            "│   Maximum number of trains that can travel  [11] │   Maximum number of trains that can    [21] │\n" // Todos os nomes destas opções sao temporarios
            "│ simultaneously between two stations              │ travel between two specific stations        │\n"
            "│                                                  │ with minimum cost for the company           │\n"
            "│   Which stations require the most amount    [12] │                                             │\n"
            "│ of trains to when taking full advantage of the   │   Maximum number of trains that can    [22] │\n"
            "│ existing network capacity                        │ travel between two specific stations        │\n"
            "│                                                  │ in a network of reduced connectivity        │\n"
            "│   Top-k municipalities and districts        [13] │                                             │\n"
            "| regarding their transportation needs             |   Report on the stations  that are the [23] |\n"
            "│                                                  │ most affected by each segment failure       │\n"
            "│   Maximum number of trains that can arrive  [14] │                                             │\n"
            "│ simultaneously at a given station                │                                             │\n"
            "│                                                  │                                             │\n"
            "╞══════════════════════════════════════════════════╧═════════════════════════════════════════════│\n"
            "│                                          Other operations                                      │\n"
            "╞══════════════════════════════════════════════════╤═════════════════════════════════════════════╡\n"
            "│  Change station preferences **temp**        [31] │ Exit                                   [41] │\n"
            "╘══════════════════════════════════════════════════╧═════════════════════════════════════════════╛\n"
            "                                                                                                  \n";
    string operation;
    cin >> operation;
    cin.ignore();
   /* try {
        switch (stoi(operation)) { // Todos os nomes destas funções sao temporarios
            case 11: {
                printMaxTrainsBetweenTwoStation();
                break;
            }
            case 12:
                printStationsMostAmountTrains();
                break;
            case 13:
                printTopkMunicipalitiesDistricts();
                break;
            case 14:
                printMaxTrainsArriveSimul();
                break;
            case 21:
                printTrainsTravelMinimumCost();
                break;
            case 22:
                printMaxTrainsReducedConnect();
                break;
            case 31:
                printPreferences();
                break;
            case 41:
                return false;
            default:
                cout << "Invalid Operation..." << endl;
        }
    }catch(std::invalid_argument){
        cout << "Invalid Operation..." << endl;
    }
    */
    return true;
}

