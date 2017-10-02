#include <bits/stdc++.h>
using namespace std;
int nodes,edges;
void print_path(vector<int> distance)
{
	cout<<"Distance of vertex corresponding from source\n";
	for(int i=0;i<distance.size();i++)
	{
		cout<<i<<"\t\t"<<distance[i]<<endl;
	}
}
void BellmanFord(vector<pair<int,pair<int,int>> > graph,int source)
{
	vector<int> distance(nodes,INT_MAX);
	unordered_map<int,int> parent_map;
	distance[source]=0;
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<edges;j++)
		{
			int source=graph[j].second.first;
			int destination=graph[j].second.second;
			int weight=graph[j].first;
			if(distance[source]!=INT_MAX&&distance[source]+weight<distance[destination])
			{
				distance[destination]=distance[source]+weight;
				parent_map[destination]=source;
			}
		}
	}

	for(int j=0;j<edges;j++)
		{
			int source=graph[j].second.first;
			int destination=graph[j].second.second;
			int weight=graph[j].first;
			if(distance[source]!=INT_MAX&&distance[source]+weight<distance[destination])
			{
				cout<<"Graph contains negative weight cycle\n";
				exit(0);
			}
		}
	print_path(distance,parent_map);
}
int main()
{
	vector<pair<int,pair<int,int>> > graph;
	cout<<"Enter number of nodes in graph\n";
	cin>>nodes;
	cout<<"Enter number of edges is graph\n";
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		int src,dest,weight;
		cout<<"Enter source vertex\n";
		cin>>src;
		cout<<"Enter destination vertex\n";
		cin>>dest;
		cout<<"Enter weight of edge\n";
		cin>>weight;
		graph.push_back(weight,make_pair(src,dest));
	}

}