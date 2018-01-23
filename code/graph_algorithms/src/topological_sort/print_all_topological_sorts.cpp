#include <iostream>
#include <vector>
using namespace std;

class Graph {
        vector<vector<int>> graph;
        vector<int> indegree;
    public:
        Graph (int);
        void insert_egde (int, int);
        void all_topo_sorts ();
        void all_topo_sorts_helper (vector<int> &, vector<bool> &);
};

Graph :: Graph (int v) {
    graph.resize (v);
    indegree.resize (v);
}

void Graph :: insert_egde (int s, int d) {
    graph[s].push_back (d);
    indegree[d]++;
}

void Graph :: all_topo_sorts () {
    vector<int> topo;
    vector<bool> visited (graph.size());
    all_topo_sorts_helper (topo, visited);
}

void Graph :: all_topo_sorts_helper (vector<int> & topo, vector<bool> & visited) {
    for (int i = 0; i < graph.size(); i++) {
        if (indegree[i] == 0 && !visited[i]) {
            for (auto j : graph[i])         // reduce indegree of outgoing vertices
                indegree[j]--;
            topo.push_back (i);           // visit this vertex
            visited[i] = true;
            all_topo_sorts_helper (topo, visited);   // recursively call this method; for all vertices which come after this one in the topological sort
            visited[i] = false;          // now backtracking
            topo.erase (topo.end() - 1);
            for (auto j : graph[i])
                indegree[j]++;
        }
    }
    if (topo.size() == graph.size()) {
        for (int i = 0; i < topo.size(); i++)
            cout << topo[i] << " ";
        cout << endl;
    }
}

int main() {
    int v, e, s, d;
    cout << "Enter number of vertices and edges : ";
    cin >> v >> e;
    Graph g (v);
    cout << "Enter the edges :\n";
    for (int i = 0; i < e; i++) {
        cin >> s >> d;
        g.insert_egde (s, d);
    }
    cout << "The topological sorts are : \n";
    g.all_topo_sorts();
    return 0;
}
