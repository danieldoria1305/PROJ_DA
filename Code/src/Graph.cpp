//
// Created by gonca on 20/03/2023.
//


#include "../include/Graph.h"
#include "../include/Station.h"
#include "../include/LoadFiles.h"

LoadFiles lf;


Graph::Graph() : n(0){}

/*
void Graph::setVisitedFalse() {
    for (auto & node : lf.getStationVector()) {
        node.setVisited(false);
    }
}
*/

bool Graph::addVertex(const string id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id));
    return true;
}

Vertex *Graph::findVertex(const string &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return this->vertexSet;
}

int Graph::getTotalStationCapacity(const string name) {
    return 0;
}

int Graph::getNumberofTrainsService(enum service service) {
    return 0;
}

string Graph::dfs_totalOfTrainsInNetwork() {
    auto source = vertexSet.front()->getId();

    int capacity=0;

    vector<string> dfs = DFS(source, capacity);


    return dfs.back();
}

vector<string> Graph::DFS(const string &source, int &capacity){
    std::vector<string> res;

    auto v1 = findVertex(source);


    if (!v1->isVisited()){
        std :: vector<string> a;
        res.push_back(source);
        v1->setVisited(true);

        cout << v1->getAdj() << "\n";
        for (auto &it : v1->getAdj()){
            capacity += it->getCapacity();
            a = DFS (it->getDest()->getId(), capacity);
            res.insert(res.end(), a.begin(), a.end());
        }
    }


    if (source == vertexSet.front()->getId()) {
        res.push_back(to_string(capacity));
    }
    return res;
}