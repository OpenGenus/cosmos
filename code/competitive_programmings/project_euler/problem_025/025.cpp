/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <bits/stdc++.h>
using namespace std;

string add(string B,string C)
    {
    string A;
    long long l2=B.length(),l3=C.length(),l1=0,temp=0,i,num;
    for(i=0;i<l2&&i<l3;++i)
        {
        num=int(B[i])+int(C[i])+temp-96;
        temp=num/10;
        A+=char(num%10+48);
        //cout<<num<< " "<<A[i]<<endl;
    }
    while(i<l2)
        {
        num=int(B[i++])+temp-48;
        temp=num/10;
        A+=char(num%10+48);
    }
    while(i<l3)
        {
        num=int(C[i++])+temp-48;
        temp=num/10;
        A+=char(num%10+48);
    }
    while(temp)
        {
        A+=char(temp%10+48);
        temp/=10;
    }
    return A;
}

int main(){
    string F[1000000];
    F[1]="1";F[2]="1";
    long long T,N,mx,i;
    cin>>T;
    while(T--)
        {
        cin>>N;
        mx=1;
        for(i=3;mx<N;++i)
            {
            if(F[i].empty())
                F[i]=add(F[i-1],F[i-2]);
            mx=F[i].length();
        }
        cout<<i-1<<endl;
    }
}