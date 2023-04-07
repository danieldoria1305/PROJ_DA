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

    int fi = maxNumTrainsTwoStations("Pombal", "Entroncamento");

    cout << fi << "\n";

    int two = maxNumReducedConnectivity("Porto Campanhã", "Espinho", "Porto Campanhã", "Lisboa Oriente");

    cout << two;


    return 0;
}


