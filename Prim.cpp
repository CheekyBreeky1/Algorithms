#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Edge {
public:
    int weight, vertex;
    Edge(int w, int v) : weight(w), vertex(v) {}

    // operator for priority queue
    bool operator>(const Edge& e) const {
        return weight > e.weight;
    }
};

void prim(int V, vector<vector<pair<int, int>>>& adj) {
    vector<bool> visited(V, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    pq.push(Edge(0, 0));

    //minimal spanning tree weight
    int mstWeight = 0;

    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        int u = e.vertex;

        // skip if vertex visited
        if (visited[u]) continue;

        visited[u] = true;
        mstWeight += e.weight;
        cout << "added vertex: " << u << " with weight " << e.weight << endl;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // add vertex in priority queue if it not visited
            if (!visited[v]) {
                pq.push(Edge(weight, v));
            }
        }
    }

    cout << "mst weight: " << mstWeight << endl;
}

void PrimTest() {
    // Vertex count
    int V = 8;

    // adjancy list for each vertex
    vector<vector<pair<int, int>>> adj(V);

    // start vertex, end vertex, weight
    adj[0].push_back({ 1, 1 });
    adj[0].push_back({ 3, 2 });
    adj[1].push_back({ 2, 5 });
    adj[3].push_back({ 2, 3 });
    adj[2].push_back({ 6, 2 });
    adj[2].push_back({ 4, 3 });
    adj[4].push_back({ 5, 4 });
    adj[5].push_back({ 6, 2 });
    adj[6].push_back({ 7, 6 });

    prim(V, adj);
}

int main() {
    PrimTest();

    return 0;
}