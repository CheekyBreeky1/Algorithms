#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Graph {
public:
    vector<string> vertexes;
    vector<pair<string, string>> edges;

    int DFS(string begin, string end, set<string> visited, int path) {
        // if vertexes not exist
        if (find(vertexes.begin(), vertexes.end(), begin) == vertexes.end() ||
            find(vertexes.begin(), vertexes.end(), end) == vertexes.end()) {
            return -1;
        }

        if (begin == end) {
            return path;
        }

        visited.insert(begin);

        int min_path = -1;

        stack<string> d;
        for (auto item : findNearVertexes(edges, begin)) {
            d.push(item);
        }

        while (!d.empty()) {
            string current = d.top();
            d.pop();

            //if vertex not visited
            if (visited.find(current) == visited.end()) {
                visited.insert(current);
                int result = DFS(current, end, visited, path + 1);

                if (result != -1 && (min_path == -1 || result < min_path)) {
                    min_path = result;
                }
            }
        }

        return min_path;
    }

    set<string> findNearVertexes(vector<pair<string, string>> edges, string vertex) {
        set<string> result;
        for (auto item : edges) {
            if (item.first == vertex) {
                result.insert(item.second);
            }
            else if (item.second == vertex) {
                result.insert(item.first);
            }
        }
        return result;
    }

    void printGraph() {
        cout << "vertexes: ";
        for (auto item : vertexes) {
            cout << item << " ";
        }
        cout << endl << "edges: ";
        for (auto item : edges) {
            cout << item.first << " " << item.second << "  ";
        }
        cout << endl;
    }
};

void fillGraph(Graph& graph) {
    vector<string> vertexes = { "A", "B", "C", "D", "E", "F", "G", "H", };
    vector<pair<string, string>> edges = { {"A","B"}, {"B","C"}, {"C","D"}, {"A","E"},
        {"E","D"}, {"A","F"}, {"E","F"}, {"F","H"}, {"F","G"}, {"H","G"}, {"G","D"} };
    for (auto item : vertexes) {
        graph.vertexes.push_back(item);
    }
    for (auto item : edges) {
        graph.edges.push_back(item);
    }

}



int main()
{
    Graph graph;
    fillGraph(graph);
    graph.printGraph();
    cout << "Shortest path:" << graph.DFS("B", "H",{}, 0) << endl;
    cout << "Shortest path:" << graph.DFS("A", "E",{}, 0) << endl;
    cout << "Shortest path:" << graph.DFS("A", "A",{}, 0) << endl;
    cout << "Shortest path:" << graph.DFS("I", "J",{}, 0) << endl;
}
