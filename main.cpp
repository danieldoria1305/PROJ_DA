#include <iostream>


#include "Code/include/LoadFiles.h"

int main() {

    LoadFiles lf;


    lf.readNetwork();

    vector<Network> network= lf.getNetworkVector();

    cout << network[2].getCapacity();



    std::cout << "\nHello, World!" << std::endl;
    return 0;
}


