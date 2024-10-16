#include<bits/stdc++.h>
using namespace std;

// O(log2(p))
int power(int base,int p,int mod){

    if(p==0)
        return 1;

    else if(p%2==0)
        return power( ((base %mod)*(base %mod)) %mod, p/2, mod);

    else if(p%2==1)
        return ( (base%mod) * (power(((base %mod)*(base %mod))%mod, p/2, mod) %mod)) %mod;
}


int main(){

    int base,p,mod;

    while(cin>>base>>p>>mod){

        cout<< power(base,p,mod) <<"\n";

    }

    return 0;
}