#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int src, dest, weight;
};


struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v != parent[v]) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void unionSets(int u, int v) {
        int uRoot = find(u);
        int vRoot = find(v);

        if (rank[uRoot] < rank[vRoot]) {
            parent[uRoot] = vRoot;
        } else if (rank[uRoot] > rank[vRoot]) {
            parent[vRoot] = uRoot;
        } else {
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }
};


bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
public:
    int V, E; 
    vector<Edge> edges;

    Graph(int vertices, int edges) : V(vertices), E(edges) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    void kruskalMST() {
        vector<Edge> result; 
        int i = 0;
        int e = 0; 

        
        sort(edges.begin(), edges.end(), compareEdges);

        DisjointSet ds(V);

        
        while (e < V - 1 && i < E) {
            Edge nextEdge = edges[i++];
            int x = ds.find(nextEdge.src);
            int y = ds.find(nextEdge.dest);

            if (x != y) {
                result.push_back(nextEdge);
                ds.unionSets(x, y);
                e++;
            }
        }

        cout << "Minimum Spanning Tree using Kruskal's algorithm:" << endl;
        for (const Edge& edge : result) {
            cout << edge.src << " - " << edge.dest << " (" << edge.weight << ")" << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    Graph g(V, E);

    cout << "Enter the edges (format: src dest weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    g.kruskalMST();

    return 0;
}
