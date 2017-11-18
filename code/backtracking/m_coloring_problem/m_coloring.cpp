#include <std/c++.h>
using namespace std;

bool graph[500][500];	//globally defined adjacency list

bool isSafe(int n, int V, int color[],int c){
	for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool ColorGraph(int V,int m,int color[], int v){
	if(v==V)return true;
	for(int c=1;c<=m;c++)
	{
		if(isSafe(v,V,color,c)){
			color[v]=c;

			if (ColorGraph (V, m, color, v+1) == true)
             return true;

         	color[v]=0;
		}
	}
	return false;
}

int main()
{
	int V=4;
	graph[0] = {0, 1, 1, 1};
    graph[1] = {1, 0, 1, 0};
    graph[2] = {1, 1, 0, 1};
    graph[3] = {1, 0, 1, 0};
    //random graph

    int m=3;	//number of colors

    int color[V];
    for (int i = 0; i < V; ++i)
    {
    	color[i]=0;
    }

    if (ColorGraph(V,m,color,0)==0)
    {
    	cout<<"Solution does not exist\n";
    }
    else{
    	cout<<"Solution Exists: Following are the assigned colors \n";
    	for (int i = 0; i < V; ++i)
    	{
    		cout<<color[i]<<" ";
    	}
    	cout<<endl;
    }
	return 0;
}
