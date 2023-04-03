//
// Created by gonca on 03/04/2023.
//




#include "../include/VertexEdge.h"

Edge::Edge(Vertex *orig, Vertex *dest, int capacity, string service) {
    this->orig=orig;
    this->dest=dest;
    this->capacity=capacity;
    this->service=service;
}

Vertex *Edge::getDest() const {
    return this->dest;
}

int Edge::getCapacity() const {
    return this->capacity;
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

void Edge::setFlow(int flow) {
    this->flow=flow;
}

int Edge::getFlow() const {
    return this->flow;
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

std::vector<Edge *> Vertex::getIncoming() const {
    return this->incoming;
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

Edge *Vertex::addEdge(Vertex *dest, int capacity, string service) {
    auto newEdge = new Edge(this, dest, capacity, service);
    adj.push_back(newEdge);
    dest->incoming.push_back(newEdge);
    return newEdge;
}

bool Vertex::removeEdge(string destID) {
    bool removedEdge = false;
    auto it = adj.begin();
    while (it != adj.end()) {
        Edge *edge = *it;
        Vertex *dest = edge->getDest();
        if (dest->getId() == destID) {
            it = adj.erase(it);
            // Also remove the corresponding edge from the incoming list
            auto it2 = dest->incoming.begin();
            while (it2 != dest->incoming.end()) {
                if ((*it2)->getOrig()->getId() == id) {
                    it2 = dest->incoming.erase(it2);
                }
                else {
                    it2++;
                }
            }
            delete edge;
            removedEdge = true; // allows for multiple edges to connect the same pair of vertices (multigraph)
        }
        else {
            it++;
        }
    }
    return removedEdge;
}

void Vertex::addAdj(Edge *Edge) {
    adj.push_back(Edge);
}
