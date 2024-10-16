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

/// utility function to get the identity matrix
void identity_matrix(int** a, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = (i == j);
}

//matrix_multiplication method
void matrix_multiplication(int** a, int** b,int SIZE)
{
    int** res = new int*[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        res[i] = new int[SIZE];
        for(int j=0;j<SIZE;j++)
        {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = res[i][j];
}

// matrix powering to nth power
void matrix_powering(int** a, int n, int** res,int num_nodes)
{
    identity_matrix(res,num_nodes);

    while (n > 0) {
        if (n % 2 == 0)
        {
            matrix_multiplication(a, a,num_nodes);
            n /= 2;
        }
        else {
            matrix_multiplication(res, a,num_nodes);
            n--;
        }
    }
    transitive_closure(res,num_nodes);
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
    int** result = new int*[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        result[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            result[i][j] = 0;
        }
    }
    matrix_powering(edges_list,num_nodes,result,num_nodes);
}
