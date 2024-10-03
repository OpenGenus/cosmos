/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <iostream>
using namespace std;

long long A[10000000],B[5000001][2];

long long steps(long long N)
{
    if(N==1)
        return 0;
    else if (N>=10000000)
    {
        if (N%2==0)
            return 1+steps(N/2);
        else
            return 1+steps(3*N+1);
    }
    else
    {

        if (A[N]!=0)
            return A[N];
        else if (N%2==0)
        {
            A[N]=1+steps(N/2);
            return A[N];
        }
        else
        {
            A[N]=1+steps(3*N+1);
            return A[N];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    long long T,N,m,n,i,s;
    cin >> T;
    //steps(5000000);
    B[1][0]=1;
    B[1][1]=0;
    for(i=2;i<=5000000;++i)
    {
        s=steps(i);
        if (s>=B[i-1][1])
        {
            B[i][0]=i;
            B[i][1]=s;
        }
        else
        {
            B[i][0]=B[i-1][0];
            B[i][1]=B[i-1][1];
        }
    }
    while(T--)
    {
        m=0;
        cin >> N;
        cout << B[N][0] << endl;
    }
    return 0;
}
