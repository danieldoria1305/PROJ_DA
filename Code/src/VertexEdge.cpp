#include "../include/VertexEdge.h"

Edge::Edge(Vertex *orig, Vertex *dest, int capacity, string service) {
    this->orig=orig;
    this->dest=dest;
    this->capacity=capacity;
    this->service=service;
    this->flow=0;
}

Vertex *Edge::getDest() const {
    return this->dest;
}

int Edge::getCapacity() const {
    return this->capacity;
}

double Vertex::getDist() const {
    return dist;
}

void Vertex::setDist(double d) {
    dist = d;
}

bool Edge::isSelected() const {
    return this->selected;
}

Vertex *Edge::getOrig() const {
    return this->orig;
}

Edge *Edge::getReverse() const {
    return this->reverse;
}

void Edge::setSelected(bool selected) {
    this->selected=selected;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse=reverse;
}

void Edge::setFlow(double flow) {
    this->flow=flow;
}

double Edge::getFlow() const {
    return this->flow;
}

string Edge::getService() const {
    return this->service;
}

int Edge::getServiceCost() const {
    return service == "STANDARD" ? 2 : 4;
}

Vertex::Vertex(string id) {
    this->id=id;
}

string Vertex::getId() const {
    return this->id;
}

std::vector<Edge *> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}

unsigned int Vertex::getIndegree() const {
    return this->indegree;
}



void Vertex::setId(string info) {
    this->id=info;
}

void Vertex::setVisited(bool visited) {
    this->visited=visited;
}

void Vertex::setIndegree(unsigned int indegree) {
    this->indegree=indegree;
}

Edge * Vertex::addEdge(Vertex *orig, Vertex *dest, int capacity, string service) {
    auto newEdge = new Edge(orig, dest, capacity, service);
    adj.push_back(newEdge);
    return newEdge;
}

bool Vertex::removeEdge(Vertex *orig, Vertex *dest) {
    for (auto it = adj.begin(); it != adj.end(); ++it) {
        Edge *edge = *it;
        if (edge->getOrig() == orig && edge->getDest() == dest) {
            adj.erase(it);
            delete edge;
            return true;
        }
    }
    return false;
}






void Vertex::setPath(Edge *path) {
    this->path=path;
}

Edge *Vertex::getPath() const {
    return this->path;
}



