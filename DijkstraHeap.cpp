#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class Graph {
public:
    vector<string> vertexes;
    //begin, end, weight
    vector<tuple<string, string, int>> edges;
};

class Dijkstra {
public:
    
    unordered_map<string, int> run(Graph graph, string start) {
        
        unordered_map<string, int> dist;
        for (auto vertex : graph.vertexes) {
            dist[vertex] = INT_MAX;
        }
        dist[start] = 0;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({ 0, start });

        // create list of adjacency
        unordered_map<string, vector<pair<string, int>>> adj;
        for (auto edge : graph.edges) {
            //0 - begin, 1 - end, 2 - weight
            string u = get<0>(edge);
            string v = get<1>(edge);
            int w = get<2>(edge);
            adj[u].push_back({ v, w });
        }

        // main cycle
        while (!pq.empty()) {
            int u_dist = pq.top().first;
            string u = pq.top().second;
            pq.pop();

            //if Dijkstra value bigger then current skip
            if (u_dist > dist[u]) {
                continue;
            }

            //if path shorter than current - update
            for (auto neighbor : adj[u]) {
                string v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }

        return dist;
    }
};

void testDijkstra() {
    Graph graph;
    graph.vertexes = { "A", "B", "C", "D", "E" };
    graph.edges = {
        {"A", "B", 1},
        {"A", "C", 4},
        {"B", "C", 2},
        {"B", "D", 5},
        {"C", "D", 1},
        {"D", "E", 3}
    };

    Dijkstra dijkstra;
    unordered_map<string, int> distances = dijkstra.run(graph, "A");

    for (auto pair : distances) {
        cout << "Distance from A to " << pair.first << " is " << pair.second << endl;
    }
}

int main() {
    testDijkstra();
    return 0;
}