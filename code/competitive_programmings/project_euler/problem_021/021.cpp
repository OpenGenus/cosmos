/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <bits/stdc++.h>
using namespace std;

long func(long n)
    {
    if(n==1)
        return 0;
    long sum=1,sq=sqrt(n);
    for(long i=2;i<sq;++i)
        {
        if(n%i==0)
            {
            sum+=(i+n/i);
        }
    }
    if(sq*sq==n)
        sum+=sq;
    return sum;
}

int main()
    {
    long t,n,i,A[2000000],j,sum=0;
    cin>>t;
    for(i=1;i<200000;++i)
            A[i]=func(i);
    while(t--)
        {
        sum=0;
        cin>>n;
        for(i=1;i<n;++i)
            {
            j=A[i];
            if(A[j]==i&&j!=i)
                {
                sum+=i;
            }
        }
    cout<<sum<<endl;
        }
}