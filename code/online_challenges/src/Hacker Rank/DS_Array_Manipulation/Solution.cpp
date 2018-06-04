#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
     unsigned long long n,t;
    cin>>n>>t;
    vector <unsigned long long> v(n,0);
    unsigned long long  maxi=0;
    for( unsigned long long i=0;i<t;i++)
    {
        unsigned long long a,b,k;
        cin>>a>>b>>k;
        v[a-1]+=k;
        if(b<=n)
            v[b]-=k;
       // cout<<endl;
        
    }
    for(unsigned long long j=1;j<n;j++)
        v[j]=v[j-1]+v[j];
      for(unsigned long long j=0;j<n;j++)
        {
        maxi=max(maxi,v[j]);
      }
    
    cout<<maxi;
    /* Enintter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
