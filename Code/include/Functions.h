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

int maxNumTrainsTwoStationsReduced(string staA, string staB, vector<Vertex*> vert);

/*
 * staA -> first station to remove
 * staB -> second station to remove
 * staA and staB should be adj from one another (validation needed in menu)
 *
 * staC -> origin
 * staD -> destination
 *
 * maxNumReducedConnectivity -> returns the max flow between staC and staD if we remove the edge that connects
 * staA and staB
 *
 */

int maxNumReducedConnectivity (string staA,string staB, string staC, string staD);

void dijkstraShortestPath(Vertex* source, Vertex* dest);

void leastCostPathAndMaxFlow(string staA, string staB);

void report (string staA, string staB, string staC, string staD);

int maxTrainsIncoming (string staA);




#endif //PROJETODA_FUNCTIONS_H


