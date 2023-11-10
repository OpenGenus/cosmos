#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

/// utility function to print the transitive closure matrix
void print_transitive_closure(int** output, int num_nodes)
{
    cout << endl;
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

/// utility function to convert powering matrix to transitive closure matrix
void transitive_closure(int** matrix, int num_nodes)
{
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            if(matrix[i][j]>0)
            {
                matrix[i][j] = 1;
            }
        }
    }
    print_transitive_closure(matrix,num_nodes);
}

/// utility function to power the matrix
void matrix_powering(int** edges_list,int num_nodes)
{
    int result[num_nodes][num_nodes];
    int** matrix = new int*[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        matrix[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            matrix[i][j] = edges_list[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < num_nodes; i++)
    {
        for ( int c = 0 ; c < num_nodes ; c++ )
        {
            for (int d = 0 ; d < num_nodes ; d++ )
            {
                for (int k = 0 ; k < num_nodes ; k++ )
                {
                    sum += matrix[c][k]*matrix[k][d];
                }
                result[c][d] = sum;
                sum = 0;
            }
         }

        for ( int c = 0 ; c < num_nodes ; c++ ) {
            for ( int d = 0 ; d < num_nodes ; d++ ) {
                matrix[c][d] = result[c][d];
                result[c][d] = 0;
            }
        }
    }
    transitive_closure(matrix,num_nodes);
}

int main()
{
    int num_nodes,num_edges;
    cin >> num_nodes >> num_edges;
    int** edges_list = new int*[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        edges_list[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            edges_list[i][j] = 0;
        }
    }
    for(int i=0;i<num_edges;i++)
    {
        int first_node,second_node;
        cin >> first_node >> second_node;
        edges_list[first_node][second_node] = 1;
        if(i<num_nodes)
            edges_list[i][i]=1;
    }

    cout << "Input Adjacent Matrix Graph:" << endl;
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            cout << edges_list[i][j] << " ";
        }
        cout << endl;
    }
    matrix_powering(edges_list,num_nodes);
    return 0;
}
