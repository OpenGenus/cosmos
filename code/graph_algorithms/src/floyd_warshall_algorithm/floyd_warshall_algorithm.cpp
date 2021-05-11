/* Part of Cosmos by OpenGenus Foundation */

#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000000

void floydWarshall(int vertex, int adjacencyMatrix[][4])
{

    // calculating all pair shortest path
    for (int k = 0; k < vertex; k++)
        for (int i = 0; i < vertex; i++)
            for (int j = 0; j < vertex; j++)
                // relax the distance from i to j by allowing vertex k as intermediate vertex
                // consider which one is better, going through vertex k or the previous value
                adjacencyMatrix[i][j] = min( adjacencyMatrix[i][j],
                                             adjacencyMatrix[i][k] + adjacencyMatrix[k][j] );

    // pretty print the graph
    printf("o/d");     // o/d means the leftmost row is the origin vertex
    // and the topmost column as destination vertex
    for (int i = 0; i < vertex; i++)
        printf("\t%d", i + 1);
    printf("\n");

    for (int i = 0; i < vertex; i++)
    {
        printf("%d", i + 1);

        for (int j = 0; j < vertex; j++)
            printf("\t%d", adjacencyMatrix[i][j]);

        printf("\n");
    }

}

int main()
{
    /*
     * input is given as adjacency matrix,
     * input represents this undirected graph
     *
     *  A--1--B
     *  |    /
     *  3   /
     *	|  1
     *  | /
     *	C--2--D
     *
     * should set infinite value for each pair of vertex that has no edge
     */
    int adjacencyMatrix[][4] = {
        {  0, 1, 3, INF},
        {  1, 0, 1, INF},
        {  3, 1, 0, 2},
        {INF, INF, 2, 0}
    };

    floydWarshall(4, adjacencyMatrix);
}
