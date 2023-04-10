#ifndef PROJETODA_STATION_H
#define PROJETODA_STATION_H

#include <string>

using namespace std;

class Station {
public:
    Station(string name, string district, string municipality, string township, string line); // Constructor
    Station(); // Default constructor
    string getName() const; // Returns the name of the station
    string getDistrict() const; // Returns the district of the station
    string getMunicipality() const; // Returns the municipality of the station
    string getTownship() const; // Returns the township of the station
    string getLine() const; // Returns the line of the station
    void setVisited(bool _bool) ;
    bool getVisited();

private:
    string name_; // Name of the station
    string district_; // District of the station
    string municipality_; // Municipality of the station
    string township_; // Township of the station
    string line_; // Line of the station
    bool visited;
};


#endif //PROJETODA_STATION_H
