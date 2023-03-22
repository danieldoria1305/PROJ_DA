//
// Created by gonca on 20/03/2023.
//

#ifndef PROJETODA_GRAPH_H
#define PROJETODA_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <list>
#include "VertexEdge.h"
#include "LoadFiles.h"
#include "Station.h"
#include "Network.h"


class Graph {

    struct Edge{
        string connectedStation;
        int capacity;
        string service;
    };

    struct Node{
        string name;
        list<Graph::Edge> adj;
        bool visited = false;
    };

    int n; // graph size
    bool hasDir;

public:
    Graph();

    void addEdge (string name, string connectedStation, int capacity, string service);

    void setVisitedFalse();

    int getTotalStationCapacity(const string name);

    int getNumberofTrainsService(const string service);

    int totalOfTrainsInNetwork ();


    void addNode(string name);

};




#endif //PROJETODA_GRAPH_H
