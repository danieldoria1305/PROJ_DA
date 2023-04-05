#include <iostream>


#include "Code/include/LoadFiles.h"
#include "Code/include/Graph.h"
#include "Code/include/VertexEdge.h"

#include "code/include/Functions.h"

using namespace std;


int main() {
    LoadFiles lf;
    lf.readStations();
    lf.readNetwork();
    lf.createAdjs();
    Graph g = lf.getGraph();

    string a = "Porto Campanhã";
    string b = "Lisboa Oriente";


    int teste = maxNumTrainsTwoStations(a, b);

    cout << teste;
    return 0;
}


