#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
public:
    int V;
    unordered_map<int, vector<int>> adj;

    Graph(int vertices) : V(vertices) {}

    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }


    void topologicalSortUtil(int v, unordered_set<int>& visited, stack<int>& s) {
        visited.insert(v);

        for (const int& neighbor : adj[v]) {
            if (visited.find(neighbor) == visited.end()) {
                topologicalSortUtil(neighbor, visited, s);
            }
        }

        s.push(v);
    }

    
    void topologicalSort() {
        unordered_set<int> visited;
        stack<int> s;

        for (const auto& pair : adj) {
            int v = pair.first;
            if (visited.find(v) == visited.end()) {
                topologicalSortUtil(v, visited, s);
            }
        }

        cout << "Topological Sorting Order:" << endl;
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter the directed edges (format: u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.topologicalSort();

    return 0;
}
