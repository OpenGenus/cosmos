#include<bits/stdc++.h>
using namespace std;
/*

    Program to Find Root of the equation by Gauss Jacobi Method
    First we need to take input of the size of matrix (example for X,Y,Z we need to take size of matrix value 3)
    then we gradually input them serially (no need to type x,y,z. for -20x type -20 )
    then we take input of foremost right value (example 20X+2Y+6Z = 28) foremost right 28 will be taken as input)
    then we take initial value of x,y,z which is 0,0,0;
    then we take how many number of steps we need (10 or 15 steps is enough for all type of equation)
    then Done

*/

int main(void)
{
    float a[10][10], b[10], x[10], y[10];
    int n = 0, m = 0, i = 0, j = 0;
    cout << "Enter size of 2D array(Square matrix) : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "Enter values no :(" << i << ", " << j << ") ";
            cin >> a[i][j];
        }
    }
    cout << "\nEnter Values to the right side of equation\n";
    for (i = 0; i < n; i++)
    {
        cout << "Enter values no :(" << i << ", " << j << ") ";
        cin >> b[i];
    }
    cout << "Enter initial values of x\n";
    for (i = 0; i < n; i++)
    {
        cout << "Enter values no. :(" << i<<"):";
        cin >> x[i];
    }
    cout << "\nEnter the no. of iteration : ";
    cin >> m;
    while (m > 0)
    {
        for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            cout<<i+1<<" "<<y[i];
        }
        cout << "\n";
        m--;
    }
    return 0;
}


