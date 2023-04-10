//
// Created by gonca on 05/04/2023.
//

using namespace std;

#include "../include/Functions.h"
LoadFiles lf2;
Graph g = lf2.getGraph();

/**
 * @complexity The time complexity of the testAndVisit function is O(1).
 * @param q
 * @param e
 * @param w
 * @param residual
 */
void testAndVisit(queue< Vertex*> &q, Edge *e, Vertex *w, double residual) {
    if (! w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

/**
 * @complexity The time complexity of the edmondsKarp function is O(EV^2), where E is the number of edges in the graph and V is the number of vertices in the graph.
 * @param source
 * @param dest
 */
void edmondsKarp(string source, string dest) {
    Vertex* s = g.findVertex(source);
    Vertex* t = g.findVertex(dest);
    if (s == nullptr || t == nullptr || s == t)
        throw logic_error("Invalid source and/or target vertex");

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

/**
 * @complexity The time complexity of the findAugmentingPath function is O(EV), where E is the number of edges in the graph and V is the number of vertices in the graph.
 * @param source
 * @param dest
 */
bool findAugmentingPath(Vertex *s, Vertex *t) {
    for(auto v : g.getVertexSet()) {
        v->setVisited(false);
    }
    s->setVisited(true);
    queue<Vertex *> q;
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
/**
 * @complexity The time complexity of the findMinResidualAlongPath function is O(P), where P is the number of edges in the path from vertex 's' to vertex 't'
 * @param s
 * @param t
 */
double findMinResidualAlongPath(Vertex *s, Vertex *t) {
    double f = INF;
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = min(f, e->getCapacity() - e->getFlow());
            v = e->getOrig();
        }
        else {
            f = min(f, e->getFlow());
            v = e->getDest();
        }
    }
    return f;
}

/**
 * @complexity The time complexity of the augmentFlowAlongPath function is O(P), where P is the number of edges in the path from vertex s to vertex t.
 * @param s
 * @param t
 * @param f
 */
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

/**
 * Ths function returns the most amount trains that can travel between two stations (staA and staB)
 * @complexity The overall time complexity of the maxNumTrainsTwoStations function is O(V^2 E).
 * @param staA
 * @param staB
 */
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

/**
 * This function returns a vector with the sequence of stations where the most amount of trains can be simultaneously
 *  @complexity the total time complexity of the function is O(n^3 * (E + V*log(V))).
 */
vector<pair<string, string>> maxMAxFlow() {

    int max=0;
    vector<pair<string, string>> res;
    vector<pair<string, string>> ret;

    for(int i = 0; i < g.getVertexSet().size() - 1; i++){
        for(int j = i + 1; j < g.getVertexSet().size(); j++){
            if (g.getVertexSet()[i]->getId() != g.getVertexSet()[j]->getId()) {
                int aux = maxNumTrainsTwoStations(g.getVertexSet()[i]->getId(), g.getVertexSet()[j]->getId());
                if (aux >= max) {
                    max = aux;
                    res.push_back(make_pair(g.getVertexSet()[i]->getId(), g.getVertexSet()[j]->getId()));
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

/**
 * @complexity The time complexity of the function is O(E * V^2).
 * @param staA
 * @param staB
 */
int maxNumTrainsTwoStationsSameDistrict(string staA, string staB){
    edmondsKarpSameDistrict(staA, staB);

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

/**
 * @complexity The time complexity of this function is O(E+V), where E is the number of edges and V is the number of vertices in the graph.
 * @param s
 * @param t
 */
bool findAugmentingPathSameDistrict(Vertex *s, Vertex *t) {
    vector<Station> stations = lf2.getStationVector();

// Pre-compute the district for the starting station
    string district = "";
    for (const auto& r : stations) {
        if (r.getName() == s->getId()) {
            district = r.getDistrict();
            break;
        }
    }

// Use an unordered_map to map station names to districts
    unordered_map<string, string> station_districts;
    for (const auto& station : stations) {
        station_districts[station.getName()] = station.getDistrict();
    }

// Cache commonly used values
    bool visited = false;
    string dest_id, orig_id;
    int capacity, flow;

    for (auto v : g.getVertexSet()) {
        v->setVisited(false);
    }

    s->setVisited(true);
    queue<Vertex*> q;
    q.push(s);

    while (!q.empty() && !t->isVisited()) {
        auto v = q.front();
        q.pop();

        for (auto e : v->getAdj()) {
            dest_id = e->getDest()->getId();
            capacity = e->getCapacity();
            flow = e->getFlow();

            // Use the unordered_map to check if the station district matches the current district
            auto it = station_districts.find(dest_id);
            if (it != station_districts.end() && it->second == district) {
                testAndVisit(q, e, e->getDest(), capacity - flow);
            }
        }

        for (auto e : v->getAdj()) {
            orig_id = e->getOrig()->getId();
            flow = e->getFlow();

            // Use the unordered_map to check if the station district matches the current district
            auto it = station_districts.find(orig_id);
            if (it != station_districts.end() && it->second == district) {
                testAndVisit(q, e, e->getOrig(), flow);
            }
        }
    }

    return t->isVisited();

}

/**
 * @complexity Therefore, the overall time complexity of edmondsKarpSameDistrict function is O(E * (E+V)), where E is the number of edges in the graph and V is the number of vertices in the graph.
 * @param source
 * @param dest
 */
void edmondsKarpSameDistrict(string source, string dest) {
    Vertex* s = g.findVertex(source);
    Vertex* t = g.findVertex(dest);
    if (s == nullptr || t == nullptr || s == t)
        throw logic_error("Invalid source and/or target vertex");

    // Reset the flows
    for (auto v : g.getVertexSet()) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }
    // Loop to find augmentation paths
    while( findAugmentingPathSameDistrict(s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}

/**
 * This function returns a list with k elements. Each element represents a district and the number of trains in that district
 * @complexity The time complexity of this function is O(n^3 log n), where n is the number of stations.
 * @param s
 * @param t
*/
vector <pair<string, int>> maxFlowDistrict(int k){
    lf2.readStations();
    vector <Station> stations = lf2.getStationVector();
    vector <pair<string, string>> used;
    vector <pair<string, int>> res;

    // Initialize res with all unique districts and 0 as their initial flow
    for (auto c : stations){
        auto it = find_if(res.begin(), res.end(), [&](const auto& d) {
            return d.first == c.getDistrict();
        });
        if (it == res.end()){
            res.push_back(make_pair(c.getDistrict(), 0));
        }
    }

    // Calculate the maximum flow between each pair of stations in the same district
    for (auto a : stations){
        for (auto b : stations){
            if (a.getName() != b.getName() && a.getDistrict() == b.getDistrict()){
                auto it = find(used.begin(), used.end(), make_pair(b.getName(), a.getName()));
                if (it == used.end()){
                    int aux = maxNumTrainsTwoStationsSameDistrict(a.getName(), b.getName());
                    for (auto& e : res) {
                        if (e.first == a.getDistrict()) {
                            used.push_back(make_pair(a.getName(), b.getName()));
                            e.second += aux;
                            aux = 0;
                        }
                    }
                }
            }
        }
    }

    // Sort districts in decreasing order of flow and return the top k
    sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    vector<pair<string, int>> ret;
    for (int j = 0; j < k && j < res.size(); j++){
        ret.push_back(res[j]);
    }
    return ret;
}

/**
 * This function returns a list with k elements. Each element represents a Municipality and the number of trains in that municipality
 * @complexity The time complexity of this function is O(n^3 log n), where n is the number of stations.
 * @param k
 */
vector <pair<string, int>> maxFlowMunicipality(int k){
    lf2.readStations();
    vector <Station> stations = lf2.getStationVector();
    vector <pair<string, string>> used;

    vector <pair<string, int>> res;

    int flag = 0;
    for (auto c:stations){
        for (auto d : res){
            if (c.getMunicipality() == d.first){
                flag = 1;
            }
        }
        if (flag == 0){
            res.push_back(make_pair(c.getMunicipality(),0));
        }
        flag = 0;
    }


    for (auto a:stations){
        for (auto b: stations){
            int flag=0;
            if (a.getName()!=b.getName()){
                if (a.getMunicipality()==b.getMunicipality()){
                    for (auto h: used){
                        if (h.first==b.getName() && h.second==a.getName()){
                            flag=1;
                        }
                    }
                    if (flag==0) {
                        int aux = maxNumTrainsTwoStationsSameMunicipality(a.getName(), b.getName());
                        for (auto &e: res) { // use a reference to update the actual element
                            if (e.first == a.getMunicipality()) {
                                used.push_back(make_pair(a.getName(), b.getName()));
                                e.second += aux;
                                aux = 0;
                            }
                        }
                    }
                }
            }
        }
    }


    sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    vector<pair<string, int>> retorno(res.begin(), res.begin()+k);

    return retorno;
}

/**
 * @complexity The time complexity of the function is O(EV^2), where E is the number of edges in the graph and V is the number of vertices in the graph.
 * @param source
 * @param dest
 */
void edmondsKarpSameMunicipality(string source, string dest) {
    Vertex* s = g.findVertex(source);
    Vertex* t = g.findVertex(dest);
    if (s == nullptr || t == nullptr || s == t)
        throw logic_error("Invalid source and/or target vertex");

    // Reset the flows
    for (auto v : g.getVertexSet()) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }
    // Loop to find augmentation paths
    while( findAugmentingPathSameMunicipality(s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}

/**
 * @complexity
 * @param s
 * @param t
 */
bool findAugmentingPathSameMunicipality(Vertex *s, Vertex *t) {
    vector <Station> stations = lf2.getStationVector();

    string Municipality;

    for (auto r : stations){
        if (r.getName() == s->getId()){
            Municipality = r.getMunicipality();
            break; // Once we find the starting station, we can exit the loop
        }
    }

    for (auto v : g.getVertexSet()) {
        v->setVisited(false);
    }
    s->setVisited(true);

    queue<Vertex*> q;
    q.push(s);

    while (!q.empty() && !t->isVisited()) {
        auto v = q.front();
        q.pop();
        for (auto e : v->getAdj()) {
            string test = e->getDest()->getId();
            for (auto g : stations) {
                if (test == g.getName() && g.getMunicipality() == Municipality) {
                    testAndVisit(q, e, e->getDest(), e->getCapacity() - e->getFlow());
                }
            }
        }
        for (auto e : v->getAdj()) {
            string test = e->getOrig()->getId();
            for (auto g : stations) {
                if (test == g.getName() && g.getMunicipality() == Municipality) {
                    testAndVisit(q, e, e->getOrig(), e->getFlow());
                }
            }
        }
    }
    return t->isVisited();}

    int maxNumTrainsTwoStationsSameMunicipality(string staA, string staB) {
    edmondsKarpSameMunicipality(staA, staB);

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

/**
 * After cutting the connection between two vertexes (staA and staB), the function returns the max flow between two
 * stations (staC and staD)
 * @complextiy
 * @param staA
 * @param staB
 * @param staC
 * @param staD
 */
int maxNumReducedConnectivity (string staA,string staB, string staC, string staD){
    lf2.readNetwork();
    vector <Vertex*> test = g.getVertexSet();

    int flag = 0;

    vector<Network> res = lf2.getNetworkVector();

    for (auto a: res){
        if (a.getStationA()==staA && a.getStationB()==staB || a.getStationA()==staB && a.getStationB()==staA){
            flag =1;
        }
    }

    if (flag == 0){
        cout << "╒════════════════════════════════════════════════════╕\n"
                "│  The connection you want to remove does not exist  │\n"
                "╘════════════════════════════════════════════════════╛\n"
                "                                                      \n";
        return -1;
    }

    else {
        Vertex *ve1, *ve2, *ve3, *ve4;
        string aux1, aux2, aux3, aux4, aux5, aux6;
        int fak1, fak2;
        for (auto a: test) {
            if (a->getId() == staA) {
                for (auto v:a->getAdj()){
                    if (v->getDest()->getId()==staB){
                        ve1=v->getDest();
                        ve2=v->getOrig();
                        aux1=v->getService();
                        fak1=v->getCapacity();
                    }
                }
                a->removeEdge(g.findVertex(a->getId()), g.findVertex(staB));
            }
            if (a->getId() == staB) {
                for (auto b:a->getAdj()){
                    if (b->getDest()->getId()==staB){
                        ve3=b->getDest();
                        ve4=b->getOrig();
                        aux2=b->getService();
                        fak2=b->getCapacity();
                    }
                }
                a->removeEdge(g.findVertex(a->getId()), g.findVertex(staA));
            }
        }

        int ret = maxNumTrainsTwoStationsReduced(staC, staD, test);
        for (auto c:test){
            if (c->getId()==staA){
                c->addEdge(ve2, ve1, fak1, aux1);
            }
            if (c->getId()==staB){
                c->addEdge(ve4, ve3, fak2, aux2);
            }
        }
        return ret;
    }
}

/**
 * @complexity The function has a time complexity of O(E^2 * V^2) in the worst case
 * @param staA
 * @param staB
 * @param vert
 */
int maxNumTrainsTwoStationsReduced(string staA, string staB, vector<Vertex*> vert){
    edmondsKarp(staA, staB);

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

/**
 * The function returns the minimum cost trip we can make between two stations (staA and staB) and its
 * max flow. The max flow we can send from one station to another with the minimum cost.
 * @complexity
 * @param source
 * @param dest
 */
void leastCostPathAndMaxFlow(string source, string dest) {
    Vertex* s = g.findVertex(source);
    Vertex* t = g.findVertex(dest);

    if (s == nullptr || t == nullptr || s == t)
        throw logic_error("Invalid source and/or target vertex");

    dijkstraShortestPath(s,t);


    // Calculate the cost and flow along the shortest path
    double cost = 0;
    double flow = INF;
    vector<Vertex*> path; // vector to store the vertices in the path
    for (auto v = t; v != s; ) {
        path.push_back(v); // add the current vertex to the path vector
        auto e = v->getPath();
        if (e->getDest() == v) {
            cost += e->getServiceCost();
            flow = min(flow, e->getCapacity() - e->getFlow());
            v = e->getOrig();
        }
        else {
            cost += e->getServiceCost();
            flow = min(flow, e->getFlow());
            v = e->getDest();
        }
    }
    path.push_back(s); // add the source vertex to the path vector

    // Reverse the path vector since it was constructed in reverse order
    reverse(path.begin(), path.end());

    // Update the flow along the shortest path
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            e->setFlow(e->getFlow() + flow);
            v = e->getOrig();
        }
        else {
            e->setFlow(e->getFlow() - flow);
            v = e->getDest();
        }
    }

    cout << "\nLeast cost path from " << source << " to " << dest << " has cost " << cost << " and max flow " << flow << endl;

    // Output the vertexes of the path
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                     Path                    │\n";
    for (auto v : path) {
        cout << "╞═════════════════════════════════════════════╡\n";
        cout << "    " << v->getId() << "\n";
    }
    cout << "╘═════════════════════════════════════════════╛\n" << endl;
}

/**
 * @complexity In this function, the time complexity is also O((E+V)logV)
 * @param source
 * @param dest
 */
void dijkstraShortestPath(Vertex* source, Vertex* dest) {
    for (auto v : g.getVertexSet()) {
        v->setVisited(false);
        v->setDist(INF);
    }

    source->setDist(0);

    priority_queue<pair<double, Vertex*>, vector<pair<double, Vertex*>>, greater<pair<double, Vertex*>>> pq;

    pq.push({ 0.0, source });

    while (!pq.empty()) {
        auto curr = pq.top().second;
        pq.pop();

        if (curr == dest) {
            return;
        }

        if (!curr->isVisited()) {
            curr->setVisited(true);

            for (auto edge : curr->getAdj()) {
                auto neighbor = edge->getDest();

                if (!neighbor->isVisited()) {
                    double newDist = curr->getDist() + edge->getServiceCost();
                    if (newDist < neighbor->getDist()) {
                        neighbor->setDist(newDist);
                        neighbor->setPath(edge);
                        pq.push({ newDist, neighbor });
                    }
                }
            }
        }
    }
}

/**
 * * After removing the connections between two stations, we evaluate the max flow we can send from one station to another
 * and this function returns that evaluation.
 * @complexity
 * @param staA
 * @param staB
 * @param staC
 * @param staD
 */
void report (string staA, string staB, string staC, string staD){
    int first = maxNumTrainsTwoStations(staC, staD);

    int second = maxNumReducedConnectivity(staA, staB, staC, staD);

    lf2.readNetwork();

    vector<Network> net = lf2.getNetworkVector();

    for (auto a: net){
        if (a.getStationA()==staA && a.getStationB()==staB){
            cout << "\n╒═══════════════════════════════════════════════════════╕\n"
                    "  The flow between the removed stations is: " << a.getCapacity() << "\n"
                    "╘═══════════════════════════════════════════════════════╛\n"
                    "                                                         \n";
        }
    }

    cout << "\n╒════════════════════════════════════════════════════════════════════════════════════════════╕\n"
            "  The max flow between " << staC << " and " << staD << " was: " << first<<
            ".\n  After the cut of the connection between " << staA << " and " << staB << ", the max flow is now: " << first-second << "\n"
            "╘════════════════════════════════════════════════════════════════════════════════════════════╛\n"
            "                                                                                       \n";

}

