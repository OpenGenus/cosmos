#include<iostream>
#define n 3//color
#define v 4//number of vertices
using namespace std;
void printArray(int a[])
{
    for( int i = 0; i<v; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
bool isSafe(int adjMatr[v][v],int i,int vertex,int assigned[v])
{
    for(int j = 0; j<vertex; j++)
    {
        if(adjMatr[vertex][j]==1)
            if (assigned[j]==i)
                return false;

    }
    return true;
}
bool color(int adjMatr[v][v], int assigned[v], int vertex)
{
//   given a vertex, assign a color, check if safe, and solve the next problem, if its solved, return true
//   else de assign the color, assign the next one, repeat.
//    if all colors are exhausted and true wasnt returned means, that the configuration given to the fun
//    does not work
    if(vertex==v)
        return true;
    for(int i = 0; i<n; i++)
    {
        assigned[vertex] = i;  //color i is chosen
        if(isSafe(adjMatr, i, vertex,assigned))
        {
            if(color(adjMatr,assigned, vertex+1)==true)
                return true;
        }
        assigned[vertex] = -1; // backtrack

    }
    return false;
}

int main()
{
    int graph[v][v] = {{1, 1, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    };
    int assigned [v] = {-1,-1,-1,-1};
    if(color(graph, assigned, 0)==true)
        printArray(assigned);
    else cout<<"not possible";

}
