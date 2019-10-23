#include<bits/stdc++.h>
using namespace std;

int root(int i,int a[]){
	while(i!=a[i]){
		a[i]=a[a[i]];
		i=a[i];
	}

	return i;
}

int find(int u,int v,int a[]){
	int root_u=root(u,a);
	int root_v=root(v,a);

	return root_u==root_v;
}

void union_set(int u,int v,int a[],int size[]){
	int root_u=root(u,a);
	int root_v=root(v,a);

	if(root_u==root_v)
		return;

	if(size[u]<size[v]){
		a[root_u]=a[root_v];
		size[root_v]+=size[root_u];
	}

	else{
		a[root_v]=a[root_u];
		size[root_u]+=size[root_v];
	}

}



int main(){
	int n,e,u,v,flag=0;;
	cin >> n >> e;;
	vector<pair<int,int> > edges;
	int a[n+1],size[n+1];

	for(int i=1;i<=n;i++){
		a[i]=i;
		size[i]=1;
	}

	while(e--){
		cin >> u >> v;
		edges.push_back(make_pair(u,v));
	}

	for(int i=0;i<edges.size();i++){

		if(find(edges[i].first,edges[i].second,a)){
			flag=1;
			break;
		}

		else
			union_set(edges[i].first,edges[i].second,a,size);
	}

	if(flag==1)
		cout << "Cycle exits";
	else
		cout << "doesnt exist";
}