#include <iostream>
#include <map>
#include <set>
#include <queue>

/* Part of Cosmos by OpenGenus Foundation */


void bestFirstSearch(int start,                                             // the node that we are currently at
                     int goal,                                              // the node that we are looking for
                     std::map<int, std::set<std::pair<int, int>>>& adjList, // the adjacency list for each node (cost, nodeNumber)
                     std::map<int, bool>& visited)                          // the 'visited' state for each node
{

    // This priority queue wil hold the node values, ordered by costs
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> Q;

    // Add the first node with cost 0 to the queue and mark it as visited
    Q.push(std::make_pair(0, start));
    visited[start] = true;

    // Repeat the algorithm until there are no more nodes left to process
    while (!Q.empty()){
        // Take the node width the minimum cost in the queue and then pop it off the queue
        int current = Q.top().second;
        Q.pop();

        std::cout<<current<<" ";

        // If this is the node that we are looking for, exit
        if (current == goal){
            return;
        }

        // Iterate over the neighbours of the current node
        for (auto neighbour : adjList[current])
            if (!visited[neighbour.second]){
                // Mark the neighbour node as visited
                visited[neighbour.second] = true;
                // Add the neighbour to the queue 
                Q.push(neighbour);
            }
    }
}

void addEdge(int a, int b, int cost, std::map<int, std::set<std::pair<int, int>>>& adjList)
{
    adjList[a].insert(std::make_pair(cost, b));
    adjList[b].insert(std::make_pair(cost, a));
}

int main()
{
    /*
     Do a best-first search in this graph from `1` looking for `5`:
     
     1 -(5)- 2 -(2)- 6
       \
        (6)   
           \ 3 -(6)- 4
               \
                (4)
                   \ 5
     */
    std::map<int, std::set<std::pair<int, int>>> adjList;
    std::map<int, bool> visited;
    addEdge(1, 2, 5, adjList);
    addEdge(1, 3, 6, adjList);
    addEdge(2, 6, 2, adjList);
    addEdge(3, 4, 6, adjList);
    addEdge(3, 5, 4, adjList);

    // Set all nodes as unvisited at first
    for (int i = 1; i <= 6; i++)
        visited[i] = false;

    // Perform a best-first-search from the node `1`, searching for `5`
    bestFirstSearch(1, 5, adjList, visited);
    //output: 1 2 6 3 5


    return 0;
}
