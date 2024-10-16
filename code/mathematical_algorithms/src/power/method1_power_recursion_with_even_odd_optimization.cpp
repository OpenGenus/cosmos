#include<bits/stdc++.h>
using namespace std;

// O(log2(p))
long long power(int base,int p){

    if(p==0)
        return 1;

    else if(p%2==0)
        return power(base*base,p/2);

    else if(p%2==1)
        return base*power(base*base,p/2);
}

int main(){

    int base,p;

    while(cin>>base>>p){

        cout<< power(base,p) <<"\n";

    }
    return 0;
}