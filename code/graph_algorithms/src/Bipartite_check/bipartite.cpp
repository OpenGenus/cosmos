#include <iostream>
#include <vector>
#include <queue>
int main()
{
    long int vertex , edge , u , v , counter ;
    bool flag = false;
    // taking n ->number of vertex  and m -> number of edges
    std::cin >> vertex >> edge;
    // adj is 2-D vector to store edges between vertex
    std::vector < std::vector < long int > > adj(vertex , std::vector <long int> ());
    // color is use to store color of vertex
    std::vector < long int > color(vertex , -1);
    std::queue < long int > q;
    // for number of edges times
    for (int i=0;i < edge; ++i)
    {
        std::cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    u=0;
    color[u]=0;
    q.push(u);
    while (!q.empty())
    {
        counter=q.front();
        q.pop();
        for (auto i=adj[counter].begin();i!=adj[counter].end(); ++i)
        {
            // updating color of vertex
            if (color[*i]==-1)
            {
                q.push(*i);
                color[*i]=1-color[counter];
            }
            else if (color[*i]==color[counter])
            {
                flag=true;
            }
        }
    }
    if ( !flag )
        std::cout << "Graph is bipartite" << "\n" ;
    else
        std::cout << "Graph is not bipartite" << "\n" ;
}
