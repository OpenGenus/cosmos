#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int dest, weight;
};


struct Vertex {
    int vertex, distance;

    
    bool operator>(const Vertex& other) const {
        return distance > other.distance;
    }
};

class Graph {
public:
    int V; 
    vector<vector<Edge>> adj;

    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }


    void addEdge(int src, int dest, int weight) {
        Edge edge = {dest, weight};
        adj[src].push_back(edge);
    }


    void dijkstra(int src) {
        vector<int> distance(V, INF);
        vector<bool> visited(V, false);

        distance[src] = 0;

        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
        pq.push({src, 0});

        while (!pq.empty()) {
            int u = pq.top().vertex;
            pq.pop();

            if (visited[u]) {
                continue;
            }

            visited[u] = true;

            for (const Edge& edge : adj[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                if (!visited[v] && distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({v, distance[v]});
                }
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

    Graph g(V);

    cout << "Enter the edges (format: src dest weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}
