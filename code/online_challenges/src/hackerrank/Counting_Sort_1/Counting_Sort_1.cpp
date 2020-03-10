#include <bits/stdc++.h>

using namespace std;

int main(){

int n ,index;
vector<int> indexCount(100) ; 
cin>>n;

for(int x = 0 ; x<n ; x++){
    cin>>index ; 
    indexCount[index]++ ;
}

for(int x=0;x<100;x++){
    cout<<indexCount[x]<<" ";
}



return 0  ;
}
