// Detect cycle in a graph using Degree of graph
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class graph {
private:
  map<int, vector<int>> adjList;
  int n, e; // no of vertices and edges
public:
  void detect_cycle();
  void input();
};

void graph::input() {
  cout << "Enter the number of vertices : \n";
  cin >> n;
  cout << "Enter the number of edges : \n";
  cin >> e;
  cout << "Enter the adj list for the undirected graph \n";
  for (int i = 0; i < e; i++) {
    int start, end;
    cin >> start;
    cin >> end;
    adjList[start].push_back(end);
    adjList[end].push_back(start);
  }
  // print adj list
  cout << "The adj list is :\n";
  for (auto &val : adjList) {
    cout << val.first << " : ";
    for (int el : val.second) {
      cout << el << " ";
    }
    cout << "\n";
  }
}

void graph::detect_cycle() {
  unordered_map<int, int> deg;
  for (int i = 0; i < n; i++) {
    deg[i] = adjList[i].size();
  }
  bool visited[n];
  for (int i = 0; i < n; i++)
    visited[i] = false;
  queue<int> q;
  while (1) {
    // pushing all degree 1 nodes into the queue
    // recursively updating the nodes with degree 1
    for (auto &val : deg) {
      if (val.second == 1 && visited[val.first] == false)
        q.push(val.first);
    }

    if (q.empty())
      break;

    while (!q.empty()) {
      int temp = q.front(); // deleting node with degree 1
      q.pop();
      visited[temp] = true;
      for (int i = 0; i < adjList[temp].size(); i++) {
        deg[adjList[temp][i]]--;
      }
    }
  }
  int f = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false)
      f = 1;
  }
  if (f == 0)
    cout << "No cycle detected !\n";

  else {
    cout << "Cycle detected \n";
    for (int i = 0; i < n; i++) {
      if (visited[i] == false)
        cout << i << " ";
    }
  }
}

int main() {
  graph g;
  g.input();
  g.detect_cycle();
  return 0;
}
