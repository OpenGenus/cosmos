#include <iostream>
#include <vector>

/* Part of Cosmos by OpenGenus Foundation */
// Floyd-Warshall algorithm. Time complexity: O(n ^ 3)
void transitive_closure_graph(std::vector<std::vector<int>> &graph) {
    int n = (int) graph.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] |= (graph[i][k] & graph[k][j]);
            }
        }
    }
}

int main() {
    std::cout << "Enter the number of vertexes:" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Enter the adjacency matrix (consisting from 0 and 1):" << std::endl;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }
    transitive_closure_graph(graph);
    std::cout << "Result:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
