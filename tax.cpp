#include <iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,s=0;
        cin>>n;
        if(n<=250000){
            n=n-s;
            cout<<n<<endl;
        }
        if(n>250000 && n<=500000){
            s=0.05*(n-250000);
            n=n-s;
            cout<<n<<endl;
        }
        if(n>500000 && n<=750000){
            s=0.10*(n-500000);
            n=n-s-12500;
            cout<<n<<endl;
        }
        if(n>750000 && n<=1000000){
            s=0.15*(n-750000);
            n=n-s-25000-12500;
            cout<<n<<endl;
        }
        if(n>1000000 && n<=1250000){
            s=0.20*(n-1000000);
            n=n-s-25000-12500-37500;
            cout<<n<<endl;
        }
        if(n>1250000 && n<=1500000){
            s=.25*(n-1250000);
            n=n-s-25000-12500-37500-50000;
            cout<<n<<endl;
        }
        if(n>1500000){
            s=0.30*(n-1500000);
            n=n-s-25000-12500-37500-50000-62500;
            cout<<n<<endl;
        }
    }

}
