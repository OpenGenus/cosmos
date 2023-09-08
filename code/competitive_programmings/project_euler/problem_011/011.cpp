/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <iostream>
using namespace std;

int main()
{
    int A[20][20];
    long long int m=0;
    for (int i=0;i<20;++i)
        for (int j=0;j<20;++j)
            cin >> A[i][j];
    for (int i=0;i<20;++i)
        for (int j=0;j<20;++j)
        {
            if (j<17)
                if (m<A[i][j]*A[i][j+1]*A[i][j+2]*A[i][j+3])
                    m=A[i][j]*A[i][j+1]*A[i][j+2]*A[i][j+3];
            if (i<17&&j<17)
                if (m<A[i][j]*A[i+1][j+1]*A[i+2][j+2]*A[i+3][j+3])
                    m=A[i][j]*A[i+1][j+1]*A[i+2][j+2]*A[i+3][j+3];
            if (i<17)
            if (m<A[i][j]*A[i+1][j]*A[i+2][j]*A[i+3][j])
                m=A[i][j]*A[i+1][j]*A[i+2][j]*A[i+3][j];
            if (i<17&&j>2)
                if (m<A[i][j]*A[i+1][j-1]*A[i+2][j-2]*A[i+3][j-3])
                    m=A[i][j]*A[i+1][j-1]*A[i+2][j-2]*A[i+3][j-3];
        }
    cout << m;
    return 0;
}