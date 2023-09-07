#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <climits>

// A utility function used to print the solution
void print_distance(std::vector<int> distance)
{
    using namespace std;
    cout << "Distance of vertex corresponding from source\n";
    for (size_t i = 0; i < distance.size(); ++i)
        cout << i << "\t\t" << distance[i] << endl;
}


// 1/29/22 -- This is an update to the existing Bellman Ford algorithm
//Given a graph and a source vertex src in graph, find shortest paths from src to
// all vertices in the given graph(Adjacency List). The graph may contain negative weight edges.

//Here we have an alternative BellmanFord solution, where the parameters are only a source vertex and graph

vector<int> bellmanFord(int src, std::vector<std::pair<int, std::pair<int, int>>> graph){
    // Number of vertices from the inputted graph
    int numVert = graph.size();
    // Vector with the shortest paths to all other vertices, will be returned at the end
    vector<int> shortestPaths;

    // Sets all of the paths to each vertex equal to INFINITY aka INT_MAX
    for (int x = 0; x < numVert; x++)
        shortestPaths.push_back(INT_MAX);

    // Sets the distance to the source vertex, itself, equal to zero
    shortestPaths[src] = 0;

    // Beginning of triple For loops to allow for relaxation of shortestPaths
    // Covers every single edge in the graph through a double for loop
    for (int i = 1; i <= numVert -1; i++){
        for (int j = 0; j < numVert; j++){

            //Iterates for the number of edges from vertex at index j
            for (int z = 0; z < graph[j].size(); z++){
                int distance = graph[j].at(z).second;
                int nextVert = graph[j].at(z).first;

                // The output vector slowly gets relaxed as iteration occurs
                if ((distance + shortestPaths[j] < shortestPaths[nextVert]) && (shortestPaths[j] != INT_MAX)){
                    shortestPaths[nextVert] = shortestPaths[j] + distance;
                }
            }
        }
    }

    //Prints shortestPaths
    print_distance(shortestPaths);
    return shortestPaths;
}
