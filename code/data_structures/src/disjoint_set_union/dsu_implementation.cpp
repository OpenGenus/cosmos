#include<bits/stdc++.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll parent[100000], Rank[100000];

void MakeSet(){
    for(ll i=1;i<=10;i++){
        parent[i]=i;
        Rank[i]=0;
    }
}

ll Find(ll i){
    while(i!=parent[i])
        i=parent[i];
    return i;
}

void Union(ll i, ll j){
    ll i_id=Find(i);
    ll j_id=Find(j);
    if(i_id==j_id)
        return;
    if(Rank[i_id]>Rank[j_id])
        parent[j_id]=i_id;
    else{
        parent[i_id]=j_id;
        if(Rank[i_id]==Rank[j_id])
            Rank[j_id]+=1;
    }
}

int main()
{
    fio;
    MakeSet();
    Union(1,2);
    Union(3,4);
    Union(1,9);
    Union(5,6);
    Union(3,7);
    Union(4,6);
    Union(2,4);
    for(ll i=1;i<=10;i++)
    {
        cout<<"Node:"<<i<<" "<<"Parent:"<<parent[i]<<" "<<"Rank:"<<Rank[i]<<endl;
    }
    return 0;
}

/*
OUTPUT
Node:1 Parent:2 Rank:0                               6              8         10
Node:2 Parent:6 Rank:1                             / | \
Node:3 Parent:4 Rank:0                            /  |  \
Node:4 Parent:6 Rank:1                           5   4   2
Node:5 Parent:6 Rank:0                              / \ / \
Node:6 Parent:6 Rank:2                             3  7 1  9
Node:7 Parent:4 Rank:0
Node:8 Parent:8 Rank:0
Node:9 Parent:2 Rank:0
Node:10 Parent:10 Rank:0
*/