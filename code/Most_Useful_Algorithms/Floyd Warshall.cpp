#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; 

class Graph {
public:
    int V; 
    vector<vector<int>> adj;

    Graph(int vertices) : V(vertices) {
    
        adj.resize(V, vector<int>(V, INF));

    
        for (int i = 0; i < V; i++) {
            adj[i][i] = 0;
        }
    }

    
    void addEdge(int src, int dest, int weight) {
        adj[src][dest] = weight;
    }

    
    void floydWarshall() {
        vector<vector<int>> dist = adj; 

        
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        
        cout << "Shortest Distances between All Pairs of Vertices:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << "INF\t";
                } else {
                    cout << dist[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter the edges and their weights (format: src dest weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    g.floydWarshall();

    return 0;
}
