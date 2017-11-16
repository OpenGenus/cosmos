/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string A[10000],name;
    int N,Q,i,j,k;
    int ans;
    cin>>N;
    for(i=0;i<N;++i)
        cin>>A[i];
    sort(A,A+N);
    cin>>Q;
    for(i=0;i<Q;++i)
        {
        ans=0;
        cin>>name;
        for(k=0;k<N;++k)
            {
            if(A[k]==name)
                {
        for(j=0;j<A[k].length();++j)
            {
            ans+=int(A[k][j])-64;}
        cout<<ans*(k+1)<<endl;
                break;}
        }
    }
    return 0;
}