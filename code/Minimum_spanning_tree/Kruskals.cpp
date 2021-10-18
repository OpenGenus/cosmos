#include<bits/stdc++.h>
using namespace std;
class edge
{
    public:
    int src;
    int dest;
    int weight;
};
int getparent(int v, vector<int> parent)
{
    if(parent[v]==v)
    return v;
    return getparent(parent[v],parent);
}
bool compare(edge e1, edge e2)
{
    return (e1.weight < e2.weight);
}
edge *kruskal(edge *graph, int v, int e)
{
    // step-1 sorting the edges on the basis of increasing order
    sort(graph,graph+e,compare);
    // create a parent matrix
    vector<int> parent(v,0);
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
    // step -3 create an output of edges (v-1)
    edge *output =new edge[v-1];
    int count=0;
    int i=0;
    while(count < (v-1))
    {
        // step -4 check the topmost parent 
        edge curredge = graph[i];
        int srcparent = getparent(curredge.src,parent);
        int destparent =getparent(curredge.dest,parent);
        if(srcparent!=destparent)
        {
            output[count] =curredge;
            count+=1;
            parent[srcparent] =destparent;
        }
        i+=1;
    }
return output;
}
int main()
{
    int v,e;
    cin>>v>>e;
    edge *graph= new edge[e];
    for(int i=0;i<e;i++)
    {
       int x,y,z;
       cin>>x>>y>>z;
       graph[i].src=x;
       graph[i].dest=y;
       graph[i].weight=z;
    }
    edge *output =kruskal(graph,v,e);
    for(int i=0;i<v-1;i++)
    {
        if(output[i].src < output[i].dest)
        {
            cout<<output[i].src<<" "<<output[i].dest<<endl;
        }
        else 
        {
            cout<<output[i].dest<<" "<<output[i].src<<endl;
        }
    }
    return 0;
}