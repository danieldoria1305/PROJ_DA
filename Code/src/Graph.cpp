//
// Created by gonca on 20/03/2023.
//


#include "../include/Graph.h"
#include "../include/Station.h"
#include "../include/LoadFiles.h"

Graph::Graph() : n(0), hasDir(true), nodes(1) {}

void Graph::setVisitedToFalse() {
    for (auto & node : getStationVector) {
        node.visited = false;
    }
}

