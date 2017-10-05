#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void printSolution(int reach[][4])
{
    cout<<"Following matrix is transitive closure of the given graph\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<reach[i][j];
        }
        cout<<endl;
    }
}
void transitiveClosure(int graph[][4])
{
    int reach[4][4], i, j, k;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            reach[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < 4; k++)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    printSolution(reach);
}
int main()
{
    int graph[4][4] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
    transitiveClosure(graph);
    getch();
}
