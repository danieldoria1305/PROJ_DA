//
// Created by gonca on 05/04/2023.
//


#include "../include/Functions.h"
LoadFiles lf2;
Graph g = lf2.getGraph();



void testAndVisit(std::queue< Vertex*> &q, Edge *e, Vertex *w, double residual) {
    if (! w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

void edmondsKarp(string source, string dest) {
    Vertex* s = g.findVertex(source);
    Vertex* t = g.findVertex(dest);
    if (s == nullptr || t == nullptr || s == t)
        throw std::logic_error("Invalid source and/or target vertex");

    // Reset the flows
    for (auto v : g.getVertexSet()) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }
    // Loop to find augmentation paths
    while( findAugmentingPath(s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}


bool findAugmentingPath(Vertex *s, Vertex *t) {
    for(auto v : g.getVertexSet()) {
        v->setVisited(false);
    }
    s->setVisited(true);
    std::queue<Vertex *> q;
    q.push(s);
    while( ! q.empty() && ! t->isVisited()) {
        auto v = q.front();
        q.pop();
        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getCapacity() - e->getFlow());
        }
        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
    return t->isVisited();
}

double findMinResidualAlongPath(Vertex *s, Vertex *t) {
    double f = INF;
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getCapacity() - e->getFlow());
            v = e->getOrig();
        }
        else {
            f = min(f, e->getFlow());
            v = e->getDest();
        }
    }
    return f;
}

void augmentFlowAlongPath(Vertex *s, Vertex *t, double f) {
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}

int maxNumTrainsTwoStations(string staA, string staB){
    edmondsKarp(staA, staB);

    vector<Vertex*> vert = g.getVertexSet();

    int max = 0;
    for (auto a:vert){
        if (a->getId()==staA){
            for (const auto e: a->getAdj()){
                max += e->getFlow();
            }
        }
    }

    return max;
}

vector<pair<string, string>> maxMAxFlow() {

    int max=0;
    vector<pair<string, string>> res;
    vector<pair<string, string>> ret;


    for (auto a:g.getVertexSet()){
        for (auto b:g.getVertexSet()){
            if (a->getId()!=b->getId()) {
                int aux = maxNumTrainsTwoStations(a->getId(), b->getId());
                if (aux >= max) {
                    max = aux;
                    res.push_back(make_pair(a->getId(), b->getId()));
                }
            }
        }
    }


    for (auto c:res){
        int flag =0;
        if (max == maxNumTrainsTwoStations(c.first,c.second)){
            for (auto d:ret){
                if (c.second==d.first && c.first==d.second){
                    flag =1;
                }
            }
            if (flag==0){
                ret.push_back(c);

            }
        }
    }

    cout << "When taking full advantage of the existing network capacity the most amount of trains "
            "that can travel between two stations is " << max << " and the pairs of stations are:\n";
    return ret;
}
