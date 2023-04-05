//
// Created by gonca on 05/04/2023.
//

#ifndef PROJETODA_FUNCTIONS_H
#define PROJETODA_FUNCTIONS_H

#include "LoadFiles.h"
#include <vector>
#include "Graph.h"
#include "Station.h"
#include "VertexEdge.h"
#include "Network.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>



void testAndVisit(std::queue< Vertex*> &q, Edge *e, Vertex *w, double residual);

void edmondsKarp (string source, string dest);

bool findAugmentingPath(Vertex *s, Vertex *t);

double findMinResidualAlongPath(Vertex *s, Vertex *t);

void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);

int maxNumTrainsTwoStations(string staA, string staB);


#endif //PROJETODA_FUNCTIONS_H


