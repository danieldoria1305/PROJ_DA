#include <iostream>

#include "Code/include/LoadFiles.h"
#include "Code/include/Graph.h"
#include "Code/include/VertexEdge.h"
#include "Code/include/App.h"
#include "Code/include/Functions.h"

using namespace std;

int main() {
/*    App a;
    a.start();*/


    LoadFiles lf;

    lf.readStations();
    lf.readNetwork();
    lf.createAdjs();
    Graph g=lf.getGraph();


    vector <Vertex*> test = g.getVertexSet();

    leastCostPathAndMaxFlow("Porto Campanhã", "Lisboa Oriente");


    return 0;
}


