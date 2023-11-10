#include <bits/stdc++.h>
using namespace std;

class brute_force
{
public:

    int shortest_path_sum(int** edges_list, int num_nodes)
    {
        int source = 0;
        vector<int> nodes;
        for(int i=0;i<num_nodes;i++)
        {
            if(i != source)
            {
                nodes.push_back(i);
            }
        }
        int n = nodes.size();
        int shortest_path = INT_MAX;
        while(next_permutation(nodes.begin(),nodes.end()))
        {
            int path_weight = 0;

            int j = source;
            for (int i = 0; i < n; i++)
            {
                path_weight += edges_list[j][nodes[i]];
                j = nodes[i];
            }
            path_weight += edges_list[j][source];

            shortest_path = min(shortest_path, path_weight);
        }
        return shortest_path;
    }
};

class dynamic_programming
{
public:
    int shortest_path_sum(int** edges_list,int** dp_array,int visited,int mask,int position,int num_nodes)
    {
        if(mask == visited)
        {
            return edges_list[position][0];
        }
        if(dp_array[mask][position] != -1)
        {
            return dp_array[mask][position];
        }

        int ans = INT_MAX;
        for(int city=0;city<num_nodes;city++){

		if((mask&(1<<city))==0){

			int newAns = edges_list[position][city] + shortest_path_sum(edges_list,dp_array,visited,mask|(1<<city), city,num_nodes);
			ans = min(ans, newAns);
		}
	}
    dp_array[mask][position] = ans;
	return dp_array[mask][position] = ans;
    }
};
int main()
{
  	/// Getting the number of nodes and number of edges as input
    int num_nodes,num_edges;
    cin >> num_nodes >> num_edges;

    /// creating a multi-dimensional array
    int** edges_list = new int*[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        edges_list[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            edges_list[i][j] = 0;
        }
    }

    /// adjacent matrix filling mechanism
    for(int i=0;i<num_edges;i++)
    {
        int first_node,second_node,weight;
        cin >> first_node >> second_node >> weight;
        edges_list[first_node][second_node] = weight;
        edges_list[second_node][first_node] = weight;

    }
    int visited = (1<<num_nodes)-1;
    int m = 1<<num_nodes;
    int** dp_array = new int*[m];
    for(int i=0;i<m;i++)
    {
       dp_array[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            dp_array[i][j] = -1;
        }
    }
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            cout << edges_list[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    brute_force approach1;
    dynamic_programming approach2;
    cout << approach1.shortest_path_sum(edges_list,num_nodes) << endl;
    cout << approach2.shortest_path_sum(edges_list,dp_array,visited,1,0,num_nodes) << endl;
  	return 0;
}
