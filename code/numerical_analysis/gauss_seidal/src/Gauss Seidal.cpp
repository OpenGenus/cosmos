#include<bits/stdc++.h>
using namespace std;

/*
    Program to Find Root of the equation by Gauss Seidal Method
    First we need to take input of the size of matrix (example for X,Y,Z we need to take size of matrix value 3)
    then we gradually input them serially (no need to type x,y,z. for -20x type -20 )
    then we take input of foremost right value (example 20X+2Y+6Z = 28) foremost right 28 will be taken as input)
    then we take initial value of x,y,z which is 0,0,0;
    then we take how many number of steps we need (10 or 15 steps is enough for all type of equation)
    then Done
*/


int main(void)
{
    float a[10][10], b[10], m[10], n[10];
    int p = 0, q = 0, i = 0, j = 0;
    cout << "Enter size of 2D array(Square matrix) : ";
    cin >> p;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < p; j++)
        {
            cout << "a[" << i << "," << j << "]=";
            cin >> a[i][j];
        }
    }
    cout << "\nEnter values to the right side of equation\n";
    for (i = 0; i < p; i++)
    {
        cout << "b[" << i << "," << j << "]=";
        cin >> b[i];
    }
    cout << "Enter initial values of x\n";
    for (i = 0; i < p; i++)
    {
        cout << "x:[" << i<<"]=";
        cin >> m[i];
    }
    cout << "\nEnter the no. of iteration : ";
    cin >> q;
    while (q> 0)
    {
        for (i = 0; i < p; i++)
        {
            n[i] = (b[i] / a[i][i]);
            for (j = 0; j < p; j++)
            {
                if (j == i)
                    continue;
                n[i] = n[i] - ((a[i][j] / a[i][i]) * m[j]);
                m[i] = n[i];
            }
            cout<<"x"<<i + 1 << "="<<n[i]<<" ";
        }
        cout << "\n";
        q--;
    }
    return 0;
}

