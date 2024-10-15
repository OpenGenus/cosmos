#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        list<int> queue;
        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (auto adjVertex : adj[s]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
        cout << endl;
    }
};
