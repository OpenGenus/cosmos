#include <iostream>

#define V 4

using namespace std;

void printResult(int color[])
{
    cout << "The colors are :  ";
    for (int i = 0; i < V; i++)
        cout <<  color[i] << " ";
    cout << "\n" ;
}

bool usable (int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool mainColoring(bool graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (usable(v, graph, color, c))
        {
            color[v] = c;

            if (mainColoring (graph, m, color, v+1) == true)
                return true;

            color[v] = 0;
        }
    }

    return false;
}
bool coloring(bool graph[V][V], int m)
{
    int *color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (mainColoring(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }

    printResult(color);
    return true;
}

int main()
{
    bool graph[V][V] =
    {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    coloring (graph, m);
    return 0;
}
