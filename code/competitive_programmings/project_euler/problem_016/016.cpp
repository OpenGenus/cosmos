/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <iostream>
#define max_size 10000
using namespace std;

int main()
{
    int T,N,m,A[max_size],i,j,c,x;
    long sum;
    cin>>T;
    while(T--)
    {
        sum=0;
        m=1;
        A[0]=1;
        for(i=1;i<max_size;++i)
            A[i]=0;
        cin >> N;
        for(i=0;i<N;++i)
        {
            c=0;
            for(j=0;j<m;++j)
            {
                x=A[j]*2+c;
                A[j]=x%10;
                c=x/10;
            }
            while(c)
            {
                A[m++]=c%10;
                c/=10;
            }
        }
        for(i=m-1;i>=0;--i)
            sum+=A[i];
        cout << sum << endl;
    }
    return 0;
}