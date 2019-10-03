#include <iostream>
#include <map>
#include <set>
#include <queue>

/* Part of Cosmos by OpenGenus Foundation */
void bfs(int start,                                                             // the node that we are currently at
         std::map<int, std::set<int>>& adjList,         // the adjacency list for each node
         std::map<int, bool>& visited,                          // the 'visited' state for each node
         std::map<int, int>& distance                           // the distance from the `start` node
         )
{
    // First, clear the distance map, so that only nodes that we can actually reach from the `start` appear in it at the end
    distance.clear();

    // This queue wil hold pairs of numbers of the form (nodeNumber, distance)
    std::queue<std::pair<int, int>> Q;

    // Add the first node with distance 0 to the queue and mark it as visited
    Q.push(std::make_pair(start, 0));
    visited[start] = true;

    // Repeat the algorithm until there are no more ndoes left to process
    while (!Q.empty())
    {
        // Take the node from the front of the queue and pop it off the queue
        auto entry = Q.front(); Q.pop();
        int node = entry.first;
        int dist = entry.second;

        // Put the distance to this node into the distance map (this is the minimal distance to this node)
        distance[node] = dist;

        // Iterate over the neighbours of the current node
        for (auto neighbour : adjList[node])
            if (!visited[neighbour])
            {
                // Mark the neighbour node as visited
                visited[neighbour] = true;
                Q.push(std::make_pair(neighbour, dist + 1));
            }
    }
}

void addEdge(int a, int b, std::map<int, std::set<int>>& adjList)
{
    adjList[a].insert(b);
    adjList[b].insert(a);
}

int main()
{
    /*
     * Do a breadth-first search in this graph:
     *
     * 1--2--4--7
     | / \    |
     |/   \   |
     | 3     5--6
     |
     | 8--9
     */
    std::map<int, std::set<int>> adjList;
    std::map<int, bool> visited;
    std::map<int, int> dist;
    addEdge(1, 2, adjList);
    addEdge(1, 3, adjList);
    addEdge(2, 3, adjList);
    addEdge(2, 4, adjList);
    addEdge(2, 5, adjList);
    addEdge(4, 7, adjList);
    addEdge(5, 6, adjList);
    addEdge(6, 7, adjList);
    addEdge(8, 9, adjList);

    // Set all nodes as unvisited at first
    for (int i = 1; i <= 8; i++)
        visited[i] = false;

    // Perform a bfs from the node `1`
    bfs(1, adjList, visited, dist);

    // Print the distance to all visited nodes
    for (auto entry : dist)
        std::cout << "Distance from 1 to " << entry.first << " is " << entry.second << std::endl;
    return 0;
}
