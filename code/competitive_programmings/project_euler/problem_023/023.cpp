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

long long A[1000000];

long long sum(long N){
    if(A[N])
        return A[N];
    A[N]=0;
    long long i,sr=sqrt(N);
    for(i=1;i<=sr;++i)
        if(N%i==0)
            A[N]+=(i+N/i);
    if(sr*sr==N)
        A[N]-=sr;
        A[N]-=N;
    return A[N];
}

bool func(long long N){
    for(long long i=1;i<=N/2+1;++i)        
            if(sum(i)>i&&sum(N-i)>N-i)
        {
         return true;}
    return false;
}

int main(){
    long long T,N;
    cin>>T;
    while(T--){
        cin>>N;
        if(func(N))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}