#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

/**
    prints all the hamiltonian paths and cycles of the graph
**/
void printPathsAndCycles(vector<vector<string> > mN,vector<vector<string> > m1, int n)
{
    cout <<"\nThe hamiltonian paths of the graph are : ";
    vector<string> paths;
    vector<string> edges;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (mN[i][j] != "0")            // prints the paths from the last mN matrix
            {
                cout <<  mN[i][j] <<", " ;
                paths.push_back(mN[i][j]);
            }

            if (m1[i][j] != "0")             // stores the edges of the m1 matrix
            {
                edges.push_back(m1[i][j]);
            }

        }
    }
    cout <<"\n";
    string edge1;
    string edge2;
    cout <<"\nThe hamiltonian cycles of the graph are : ";
    for (int i=0; i<paths.size(); i++)
    {
        edge2 = paths[i].substr(paths[i].length()-1,1)+paths[i].substr(0,1); // edge that consists of the 1st and the last path nodes
        for (int j=0; j<edges.size(); j++)
        {
            if (edge2.compare(edges[j]) == 0)                         // checks if the there is an edge that connects the path to make a cycle
            {
                cout << paths[i] << paths[i].substr(0,1) << ", ";
            }
        }
    }
}

int main()
{
    char c;
    vector<char> lines;
    ifstream in ("hamilton.txt"); // opens text file that contains the graph
    int n=0;
    if (in.is_open())
    {
        while ( in >> c )
        {
            lines.push_back(c); // stores graph to memory
        }
        in.close();
    }
    n = sqrt(lines.size());     // number of nodes of the graph
    vector<vector<string> > m(n);
    for (int i=0; i<n; i++)
    {
        m[i].resize(n);
        for (int j=0; j<n; j++)
        {
            m[i][j] = lines[i*n+j];  // makes the M matrix
        }
    }

    vector<vector<string> > m1(n);
    for (int i=0; i<n; i++)
    {
        m1[i].resize(n);
        for (int j=0; j<n; j++)
        {
            if (m[i][j] != "0")
            {
                m1[i][j] = char(65+i) + m[i][j]; // makes the M1 matrix from the M matrix, where 65 is the char 'A'
            }
            else
            {
                m1[i][j] = m[i][j]; // element of M1 becomes 0, because the element of M is 0
            }
        }
    }
    vector<vector<string> > temp = m1; // save the starting state of M1 cause it is changed later(M1 becomes the MN-1 matrix)
    vector<vector<string> > mN(n);
    for (int i=0; i<n; i++)
    {
        mN[i].resize(n);
        for (int j=0; j<n; j++)
        {
            mN[i][j] = "0";
        }
    }
    for (int a=1; a<n-1; a++)       // makes the MN matrices using the M and MN-1 matrices
    {
        for (int r=0; r<n; r++)     //
        {
            for (int s=0; s<n; s++)
            {
                for (int t=0; t<n; t++)
                {
                    if (m1[r][t] != "0" && m[t][s] != "0" && m1[r][t].find(m[t][s]) == string::npos )  // MN-1 element cant be 0 , M element cant be 0 and MN-1 cant contain the element from M
                        mN[r][s] = m1[r][t] + m[t][s];     // MN becomes the "union" of the M and MN-1 matrices
                }
            }
        }
        if (a!=n-2)                  //  make M1 the MN-1 matrix and empty the MN matrix
        {
            m1 = mN;
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    mN[i][j] = "0";
                }
            }
        }

    }

    printPathsAndCycles(mN,temp,n);       // temp is the saved state of M1 matrix
}
