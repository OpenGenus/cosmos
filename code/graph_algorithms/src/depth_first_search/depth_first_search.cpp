#include <iostream>
#include <map>
#include <set>

/* Part of Cosmos by OpenGenus Foundation */
void dfs(int current,                                                   // the node that we are currently at
         std::map<int, std::set<int>>& adjList,         // the adjacency list for each node
         std::map<int, bool>& visited)                          // the 'visited' state for each node
{
    if (visited[current])
        return;
    visited[current] = true;
    for (auto neighbour : adjList[current])
        dfs(neighbour, adjList, visited);
}

void addEdge(int a, int b, std::map<int, std::set<int>>& adjList)
{
    adjList[a].insert(b);
    adjList[b].insert(a);
}

int main()
{
    /*
     * Do a depth-first search in this graph:
     *
     * 1--2--4
     | /
     |/
     | 3
     |
     | 5--6--7
     |
     | 8
     */
    std::map<int, std::set<int>> adjList;
    std::map<int, bool> visited;
    addEdge(1, 2, adjList);
    addEdge(1, 3, adjList);
    addEdge(2, 3, adjList);
    addEdge(2, 4, adjList);
    addEdge(5, 6, adjList);
    addEdge(6, 7, adjList);
    addEdge(6, 8, adjList);

    // Set all nodes as unvisited at first
    for (int i = 1; i <= 8; i++)
        visited[i] = false;

    // Perform a dfs from the node `1`
    dfs(1, adjList, visited);

    // Print all the visited nodes:
    for (int i = 1; i <= 8; i++)
        if (visited[i])
            std::cout << i << " ";

    return 0;
}
