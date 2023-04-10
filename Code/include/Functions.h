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

/*
 * Exercise 2.1
 *
 * The most amount trains that can travel between two stations (staA and staB)
 *
 * staA -> one of the stations
 * staB -> the other station
 *
 *
 */
int maxNumTrainsTwoStations(string staA, string staB);

void testAndVisit(std::queue< Vertex*> &q, Edge *e, Vertex *w, double residual);

void edmondsKarp (string source, string dest);

bool findAugmentingPath(Vertex *s, Vertex *t);

double findMinResidualAlongPath(Vertex *s, Vertex *t);

void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);

/*
 *Exercise 2.2
 *
 * Returns a vector with the sequence of stations where the most amount of trains can be simultaneously
 *
 *
 */
vector<pair<string, string>> maxMAxFlow();

/*
 *
 * Exercise 2.3
 *
 * Returns a list with k elements. Each element represents a district and the number of trains in that district
 *
 * k -> the size of the list we want to see
 *
 */
vector <pair<string, int>> maxFlowDistrict(int k);

int maxNumTrainsTwoStationsSameDistrict(string staA, string staB);

void edmondsKarpSameDistrict(string source, string dest);

bool findAugmentingPathSameDistrict(Vertex *s, Vertex *t);

/*
 *
 * Exercise 2.3
 *
 * Returns a list with k elements. Each element represents a Municipality and the number of trains in that municipality
 *
 * k -> the size of the list we want to see
 *
 */
vector <pair<string, int>> maxFlowMunicipality(int k);

int maxNumTrainsTwoStationsSameMunicipality(string staA, string staB);

void edmondsKarpSameMunicipality(string source, string dest);

bool findAugmentingPathSameMunicipality(Vertex *s, Vertex *t);

/*
 * Exercise 3.1
 *
 * The functions returns the minimum cost trip we can make between two stations (staA and staB) and its
 * max flow. The max flow we can send from one station to another with the minimum cost.
 *
 * staA -> origin
 * staB -> destination
 */
void leastCostPathAndMaxFlow(string staA, string staB);

void dijkstraShortestPath(Vertex* source, Vertex* dest);


/*
 *
 * Exercise 4.1
 *
 * After cutting the connection between two vertexes (staA and staB), the functions returns the max flow between two
 * stations (staC and staD)
 *
 * staA -> first station to remove
 * staB -> second station to remove
 * staA and staB should be adj from one another (validation needed in menu)
 *
 * staC -> origin
 * staD -> destination
 *
 *
 */

int maxNumReducedConnectivity (string staA,string staB, string staC, string staD);

int maxNumTrainsTwoStationsReduced(string staA, string staB, vector<Vertex*> vert);

/*
 * Exercise 4.2
 *
 *
 * After removing the connections between two stations, we evaluate the max flow we can send from one station to another
 *
 * Remove connection between staA and staB
 * evaluates max flow between staC and staD
 */

void report (string staA, string staB, string staC, string staD);


#endif //PROJETODA_FUNCTIONS_H


