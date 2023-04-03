#include <iostream>


#include "Code/include/LoadFiles.h"
#include "Code/include/Graph.h"
#include "Code/include/VertexEdge.h"

using namespace std;


int main() {


    LoadFiles lf;




    Graph g = lf.readStations();




    string test = g.dfs_totalOfTrainsInNetwork();

    std::cout << test << "\n THis is the line \n";

    std::cout << "\nHello, World!" << std::endl;
    return 0;
}


