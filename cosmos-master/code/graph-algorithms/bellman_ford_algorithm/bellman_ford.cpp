#include <bits/stdc++.h>
using namespace std;
int nodes,edges;
// Path of Cosmos by OpenGenus Foundation
void path_finding(int source,unordered_map<int,int> parent_map)
{
	string str;
	while(parent_map[source]!=source)
	{
		str.append(to_string(source));
		str.append(" ");
		source=parent_map[source];
	}
	str.append(to_string(source));
	reverse(str.begin(),str.end());
	cout<<"Path\n";
	cout<<str<<endl;
}
void print_distance(vector<int> distance)
{
	cout<<"Distance of vertex corresponding from source\n";
	for(int i=0;i<distance.size();i++)
	{
		cout<<i<<"\t\t"<<distance[i]<<endl;
	}
}
void BellmanFord(vector<pair<int,pair<int,int>> > graph,int source,unordered_map<int,int> &parent_map)
{
	vector<int> distance(nodes,INT_MAX);
	distance[source]=0;
// Relax all edges nodes-1 times to get the shortest possible distance
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
/* If after relaxing all edges for nodes-1 time we still get a shorter path that indicates
 a negative weight cycle */
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
	print_distance(distance);
}
int main()
{
	vector<pair<int,pair<int,int>> > graph;
	unordered_map<int,int> parent_map;
	int source,init_path;
	cout<<"Enter number of nodes in graph\n";
	cin>>nodes;
	cout<<"Enter number of edges is graph\n";
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		int src,dest,weight;
		cout<<"Enter source vertex(zero indexed)\n";
		cin>>src;
		cout<<"Enter destination vertex(zero indexed)\n";
		cin>>dest;
		cout<<"Enter weight of edge\n";
		cin>>weight;
		graph.push_back(make_pair(weight,make_pair(src,dest)));
	}
	cout<<"Enter initial vertex(zero indexed)\n";
	cin>>source;
	BellmanFord(graph,source,parent_map);
	cout<<"Enter destination vertex for path finding(zero indexed)\n";
	cin>>init_path;
	path_finding(init_path,parent_map);
	return 0;
}
