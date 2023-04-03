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
#include "Station.h"
#include "Network.h"


class Graph {

    int n; // graph size

public:
    // ~Graph();

    Graph();

    bool addVertex(const string id);

    static Vertex *findVertex(const string &id) const;

    int getNumVertex() const;

    std::vector<Vertex *> getVertexSet() const;

    // void setVisitedFalse();

    int getTotalStationCapacity(const string name);

    int getNumberofTrainsService(enum service service);

    string dfs_totalOfTrainsInNetwork ();

    vector<string> DFS (const string &source, int &capacity);



protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;

};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);



#endif //PROJETODA_GRAPH_H
