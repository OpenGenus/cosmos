// Question link : https://www.codechef.com/submit/PBATTLE

//Author - Vishwas Kapoor
#include<bits/stdc++.h>
using namespace std;
#define int   long long
#define IOS      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
int n;
cin>>n;
vector<pair<int,int>> pg; // pokemon ground
fl(n){
    int x;
    cin>>x;
    pg.push_back({x,i});
}
vector<int>pw; // pokemon water

fl(n){
    int x;
    cin>>x;
    pw.push_back(x);
}
sort(pg.begin(), pg.end() );

priority_queue<int>pq;

pq.push(pw[pg[n-1].second]);


int count = 1;

for(int i = n-2; i >= 0; i--){

    pq.push(pw[pg[i].second]);
    
    if(pq.top() == pw[pg[i].second])
        count++; 
}

cout<<count<<endl;

}
signed main(){
IOS
int t;
cin>>t;
while(t--)
goddamn();


return 0;
}
