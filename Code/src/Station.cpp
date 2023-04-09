//
// Created by danieldoria on 15-03-2023.
//

#include "../include/Station.h"

Station::Station(string name, string district, string municipality, string township, string line) {
    name_=name;
    district_=district;
    municipality_=municipality;
    township_=township;
    line_=line;
    visited=false;
}

string Station::getName() const {
    return name_;
}

string Station::getDistrict() const {
    return district_;
}

string Station::getMunicipality() const {
    return municipality_;
}

string Station::getTownship() const {
    return township_;
}

string Station::getLine() const {
    return line_;
}

void Station::setVisited(bool _bool) {
    this->visited=_bool;
}

bool Station::getVisited() {
    return this->visited;
}