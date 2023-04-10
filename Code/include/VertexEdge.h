#ifndef PROJETODA_VERTEXEDGE_H
#define PROJETODA_VERTEXEDGE_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class Edge;

#define INF std::numeric_limits<double>::max()



/************************* Vertex  **************************/

class Vertex {
public:



    Vertex(string id);
    // bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue

    string getId() const;
    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    // bool isProcessing() const;
    unsigned int getIndegree() const;
    // double getDist() const;
    Edge *getPath() const;

    double getDist() const;
    void setDist(double d);
    void setId(string info);
    void setVisited(bool visited);
    // void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    // void setDist(double dist);
    void setPath(Edge *path);
    Edge * addEdge(Vertex* orig, Vertex *dest, int capacity, string service);
    bool removeEdge(Vertex *orig, Vertex *dest);
    // friend class MutablePriorityQueue<Vertex>;
protected:
    string id;                // identifier
    std::vector<Edge *> adj;  // outgoing edges
    double dist;
    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    // bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    // double dist = 0;
    Edge *path = nullptr;

    // std::vector<Edge *> incoming; // incoming edges

    // int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, int capacity, string service);

    Vertex * getDest() const;
    int getCapacity() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;
    string getService() const;
    int getServiceCost() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setFlow(double flow);
protected:
    Vertex * dest; // destination vertex
    int capacity; // edge weight, can also be used for capacity
    string service;

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    double flow; // for flow-related problems
};



#endif //PROJETODA_VERTEXEDGE_H
