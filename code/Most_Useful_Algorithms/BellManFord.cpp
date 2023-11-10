#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; 


struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    int V, E; 
    vector<Edge> edges;

    Graph(int vertices, int edges) : V(vertices), E(edges) {}

    
    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }


    void bellmanFord(int src) {
        vector<int> distance(V, INF);
        distance[src] = 0;

        
        for (int i = 1; i <= V - 1; i++) {
            for (const Edge& edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int weight = edge.weight;

                if (distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }

    
        for (const Edge& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                cout << "Graph contains negative-weight cycle." << endl;
                return;
            }
        }

        cout << "Shortest Distances from Source Vertex " << src << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            if (distance[i] == INF) {
                cout << "INF" << endl;
            } else {
                cout << distance[i] << endl;
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    Graph g(V, E);

    cout << "Enter the edges and their weights (format: src dest weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    g.bellmanFord(src);

    return 0;
}
