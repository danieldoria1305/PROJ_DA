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

void edmondsKarpSameDistrict(string source, string dest);

bool findAugmentingPathSameDistrict(Vertex *s, Vertex *t);

int maxNumTrainsTwoStationsSameDistrict(string staA, string staB);

void edmondsKarpSameMunicipality(string source, string dest);

bool findAugmentingPathSameMunicipality(Vertex *s, Vertex *t);

int maxNumTrainsTwoStationsSameMunicipality(string staA, string staB);

bool findAugmentingPath(Vertex *s, Vertex *t);

double findMinResidualAlongPath(Vertex *s, Vertex *t);

void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);

int maxNumTrainsTwoStations(string staA, string staB);

vector<pair<string, string>> maxMAxFlow();

vector <pair<string, int>> maxFlowDistrict(int k);

vector <pair<string, int>> maxFlowMunicipality(int k);



#endif //PROJETODA_FUNCTIONS_H


