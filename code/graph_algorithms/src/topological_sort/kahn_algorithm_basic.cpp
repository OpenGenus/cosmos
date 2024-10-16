/*
* Implementation of the Kahn's algorithm
* for topological sort in a directed acyclic graph
*/

#include <iostream>
#include "bits/stdc++.h"

using namespace std;

queue<int> q, q2;
long long n = 100000;
int v, e, v1, v2, visited[10000], level[100000], indegree[100000];
vector<int> g[100000];

void bfs(int i)
{

  while (!q.empty())
  {
    for (int j = 0; j < g[q.front()].size(); j++)
    {
      indegree[g[q.front()][j]]--;
    }
    for (int j = 0; j < g[q.front()].size(); j++)
    {
      if (visited[g[q.front()][j]] != 1)
      {
        if (indegree[g[q.front()][j]] == 0)
        {
          q.push(g[q.front()][j]);
          visited[g[q.front()][j]] = 1;
        }
      }
    }
    cout << q.front() << " ";
    q.pop();
  }
}

int main()
{

  int v, e, v1, v2;
  cin >> v >> e;

  g[v + 1].resize(v + 1);

  for (int i = 0; i < e; i++)
  {
    cin >> v1 >> v2;
    g[v1].push_back(v2);
    indegree[v2]++;
  }

  cout << "Nodes and indegrees\n";
  for (int i = 1; i <= v; i++)
  {
    cout << i << " " << indegree[i] << endl;
  }

  cout << "Topological sort order :";
  for (int i = 1; i < v + 1; i++)
    if (indegree[i] == 0)
    {
      q.push(i);
      visited[i] = 1;
    }
  bfs(1);

  cout << endl;
}
