#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Graph {
public:
    vector<string> vertexes;
    vector<pair<string, string>> edges;

    int BFS(string begin, string end) {

        if (begin == end) {
            return 0;
        }

        queue<string> q;
        set<string> Visited;

        q.push(begin);
        Visited.insert(begin);

        int path = 0;
        string lastVertex = "";
        while (!q.empty()) {
            string currentVertex = q.front();
            q.pop();
            Visited.insert(currentVertex);

            set<string> nearVertexes = findNearVertexes(edges, currentVertex);

            for (auto item : nearVertexes) {
                if(Visited.find(item) == Visited.end())
                    q.push(item);
                if (item == end) {
                    path += 1;
                    return path;
                }
            }
            if (lastVertex == currentVertex or lastVertex == "") {
                if (!q.empty())
                    lastVertex = q.back();
                path += 1;
            }
        }
        return -1;
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

void fillGraph(Graph &graph) {
    vector<string> vertexes = { "A", "B", "C", "D", "E", "F", "G", "H", };
    vector<pair<string, string>> edges = { {"A","B"}, {"B","C"}, {"C","D"}, {"A","E"},
        {"E","D"}, {"A","F"}, {"E","F"}, {"F","H"}, {"F","G"}, {"H","G"}, {"G","D"}};
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
    cout << "Shortest path:" << graph.BFS("B", "H") << endl;
    cout << "Shortest path:" << graph.BFS("A", "E") << endl;
    cout << "Shortest path:" << graph.BFS("A", "A") << endl;
    cout << "Shortest path:" << graph.BFS("I", "J") << endl;
}
