/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <bits/stdc++.h>
using namespace std;

long long fact(long long n)
    {
    if(n==0)
        return 1;
    return n*fact(n-1);
}

int main(){
    long long t,n,i,f,p,temp,l,j;
    string B="abcdefghijklm",A;
    l=B.length();
    cin>>t;
    while(t--){
        cin>>n;
        n--;
        A=B;
        for(i=0;i<l-1;++i){
            f=fact(l-1-i);
            p=i+n/f;
            n%=f;
            for(j=i+1;j<=p;++j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            }
        }
        cout<<A<<endl;
    }
    return 0;
}