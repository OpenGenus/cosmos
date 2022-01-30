#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <climits>
#include <chrono>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int nodes, edges;
// Path of Cosmos by OpenGenus Foundation
// function to calculate path from source to the given destination
void path_finding(int source, std::unordered_map<int, int> parent_map)
{
    using namespace std;
    string str;
    while (parent_map[source] != source)
    {
        str.append(to_string(source));
        str.append(" ");
        source = parent_map[source];
    }
    str.append(to_string(source));
    reverse(str.begin(), str.end());
    cout << "Path\n";
    cout << str << endl;
}
// A utility function used to print the solution
void print_distance(std::vector<int> distance)
{
    using namespace std;
    cout << "Distance of vertex corresponding from source\n";
    for (size_t i = 0; i < distance.size(); ++i)
        cout << i << "\t\t" << distance[i] << endl;
}

// Generates a random single-solution maze adjacency list using a version of DFS, then removes walls to introduce more solutions
std::vector<std::unordered_set<int>> generateGraph(int size)
{
    // Graph adjacency list
    std::vector<std::unordered_set<int>> adjList(size * size);
    // Set of visited vertices
    std::vector<bool> v(size * size);
    // Stack of vertices to visit next...
    // NOTE: the pair consists of first: the vertex to be visited and second: which vertex it is visited from
    std::stack<std::pair<int,int>> s;
    //Push first vertex into stack with unused "from" value
    s.emplace(0, -1);

    // Visits each vertex exactly once
    while (!s.empty()) {

        // Get node to be visited and the node it is visited from
        int u = s.top().first;
        int from = s.top().second;
        s.pop();
        // If it has already been visited, move on
        if (v[u])
            continue;
        // Otherwise, mark it as visited
        v[u] = true;
        // Excluding the first node, add the edge to the adjacency list
        if (from != -1) {
            adjList[from].insert(u);
            adjList[u].insert(from);
        }

        // Create vector of unvisited neighbors
        std::vector<int> neighbors;
        if (u / size > 0 && !v[u - size])
            neighbors.push_back(u - size);
        if (u % size < size - 1 && !v[u + 1])
            neighbors.push_back(u + 1);
        if (u / size < size - 1 && !v[u + size])
            neighbors.push_back(u + size);
        if (u % size > 0 && !v[u - 1])
            neighbors.push_back(u - 1);

        // Push neighbors onto the stack in random order
        if (!neighbors.empty()) {
            random_shuffle(neighbors.begin(), neighbors.end());
            for (auto neighbor : neighbors)
                s.emplace(neighbor, u);
        }
    }

    // Remove some walls to create more solutions
    for (int i = 0; i < std::max(size, size); i++) {
        // Choose a random vertex
        int u = rand() % (size * size);
        // Create vector of *potential* neighbors of u
        std::vector<int> neighbors;
        if (u / size > 0 && !adjList[u].count(u - size))
            neighbors.push_back(u - size);
        if (u % size < size - 1 && !adjList[u].count(u + 1))
            neighbors.push_back(u + 1);
        if (u / size < size - 1 && !adjList[u].count(u + size))
            neighbors.push_back(u + size);
        if (u % size > 0 && !adjList[u].count(u - 1))
            neighbors.push_back(u - 1);
        // Knock down a random wall (make a connection with a random neighbor)
        if (!neighbors.empty()) {
            int v = neighbors[rand() % neighbors.size()];
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
    }

    // Finally, return the completed adjacency list for underlying graph
    return adjList;
}

//bellmanFord
void bellmanFord_Unweighted(vector<unordered_set<int>>& adjList, int src, int end)
{
    auto start = chrono::high_resolution_clock::now();
    vector<int> d(adjList.size(), 9999999);
    vector<int> p(adjList.size(), -1);
    d[src] = 0;
    p[src] = 0;
    for (unsigned int j = 0; j < adjList.size() - 1; j++)
    {
        for (unsigned int i = 0; i < adjList.size(); i++)
        {
            for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it)
            {
                if (d[*it] > d[i] + 1)
                {
                    d[*it] = d[i] + 1;
                    p[*it] = i;
                }
            }
        }
    }
    auto stopTime = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = stopTime - start;
    cout << endl;
    cout << endl;
    cout << "Using Bellman-Ford" << endl;
    cout << "Finding " << end << " from " << src << " using Bellman-Ford took "
         << duration.count() << " seconds" << endl;
    cout << "Verticies visited " << d[end] << endl;
    cout << endl;
}



// The main function that finds the minimum distance from the source to all other
// vertices using Bellmann ford algorithm
// The function also detects negative weight cycle
void BellmanFord(std::vector<std::pair<int, std::pair<int, int>>> graph, int source,
                 std::unordered_map<int, int> &parent_map)
{
//    using namespace std;
    vector<int> distance(nodes, INT_MAX);
    distance[source] = 0;
// Relax all edges nodes-1 times to get the shortest possible distance
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < edges; j++)
        {
            int source = graph[j].second.first;
            int destination = graph[j].second.second;
            int weight = graph[j].first;
            if (distance[source] != INT_MAX && distance[source] + weight < distance[destination])
            {
                distance[destination] = distance[source] + weight;
                parent_map[destination] = source;
            }
        }
/* If after relaxing all edges for nodes-1 time we still get a shorter path that indicates
 * a negative weight cycle */
    for (int j = 0; j < edges; j++)
    {
        int source = graph[j].second.first;
        int destination = graph[j].second.second;
        int weight = graph[j].first;
        if (distance[source] != INT_MAX && distance[source] + weight < distance[destination])
        {
            cout << "Graph contains negative weight cycle\n";
            exit(0);  // If negative cycle found then terminate the program
        }
    }
    print_distance(distance);
}
int main()
{
    using namespace std;
    vector<pair<int, pair<int, int>>> graph;
    unordered_map<int, int> parent_map;
    int source, init_path;
    cout << "Would you like to observe bellman-ford on a weighted graph or unweighted"  << endl;
    cout << "Enter 0 for weighted and 1 for unweighted" << endl;
    int choice;
    cin >> choice;
    // This creates a square graph that is unweighted (weight = 1) that allows user to input size of graph
    // and observe the times bellman-ford takes for graphs of different sizes
    while (choice == 1){
        int size = 0;
        cout << "What size graph would you like to run the bellmen-ford algorithm on? " << endl;
        cout << "Enter length, graph will be in the shape of a square so total nodes = length squared" << endl;
        cin >> size;
        auto unwieghted_graph = generateGraph(size);
        bellmanFord_Unweighted(unwieghted_graph, 0, (size * size) - 1);
        cout << endl;
        cout << "Enter 1 to run again with different size, enter 0 to create weighted graph and 3 to exit" << endl;
        cin >> choice;
    }
    if (choice == 0) {
        cout << "Enter number of nodes in graph\n";
        cin >> nodes;
        cout << "Enter number of edges is graph\n";
        cin >> edges;
        for (int i = 0; i < edges; i++) {
            int src, dest, weight;
            cout << "Enter source vertex(zero indexed)\n";
            cin >> src;
            cout << "Enter destination vertex(zero indexed)\n";
            cin >> dest;
            cout << "Enter weight of edge\n";
            cin >> weight;
            graph.push_back(make_pair(weight, make_pair(src, dest)));
        }
        cout << "Enter initial vertex(zero indexed)\n";
        cin >> source;
        BellmanFord(graph, source, parent_map);
        cout << "Enter destination vertex for path finding(zero indexed)\n";
        cin >> init_path;
        path_finding(init_path, parent_map);
    }
    return 0;
}
