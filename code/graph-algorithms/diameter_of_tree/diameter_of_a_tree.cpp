#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
using namespace std;
int n,x,y,max_distance,*dist;
vector<int> *graph;
bool *flag;
int dfs(int start)
{
    fill(flag, flag+n+1, false);
    fill(dist, dist+n+1, 0);
    stack<int> s;
    s.push(start);
    flag[start]=true;
    while(!s.empty())
    {
        int position=s.top();
        s.pop();
        for(int i=0; i < graph[position].size(); i++)
        {
            int current = graph[position][i];
            if(flag[current]==false)
            {
                flag[current]=true;
                s.push(current);
                dist[current]=max(dist[current],dist[position]+1);
            }
            
        }
    }
    int max_distance=0,index=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]>max_distance)
        {
            max_distance=dist[i];
            index=i;
        }
    }
    return index;
}
int main()
{ 
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    graph = new vector<int>[n+1];
    flag = new bool[n+1];
    dist = new int[n+1];
    printf("Enter the %d edges (numbering is from 1 to %d)\n",n-1,n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int endpoint1 = dfs(1);  // Get the farthest node from any random node
    int endpoint2 = dfs(endpoint1); // The farthest node from previous farthest node is the diameter of the tree
    printf("The diameter of tree is %d\n.", dist[endpoint2]);
	return 0;
}

// INPUT
// =====

// Enter the number of nodes : 5
// Enter the 4 edges (numbering is from 1 to 5)
// 1 2
// 3 1
// 1 4
// 5 1

// OUTPUT
// ======
// The diameter of tree is 2.