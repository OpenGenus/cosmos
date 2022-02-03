vector<int> bellmanFord(vector<vector<int>>,int src, int V){
    
    // Step 1 - Creating a V sized array/vector,
    
    vector<int> dis(V,INT_MAX); // Creating a vector dis of size V with values as INT_MAX.
    dis[src] = 0; 
    
    // Step 2 - For V-1 times, traversing over,
    // all the edges and checking if a shorter.

    int u,v,wt;

    for(int i=0;i<V-1;i++) 
    {
        for(int j=0;j<edges.size();j++) 
        {
            u = edges[j][0]; // Source vertex.
            v = edges[j][1]; // Destination vertex.
            wt = edges[j][2];// Weight of the edge. 
            
            if(dis[u]!=INT_MAX && dis[v] > dis[u] + wt)
                dis[v] = dis[u] + wt;
        }
    }
    
    // Step 3 - Checking for negative edge weight cycle, 
    
    for(int j=0;j<edges.size();j++)
    {
        u = edges[j][0];
        v = edges[j][1];
        wt = edges[j][2];

        // If the below condition satisfies, it means negative 
        // edge weight cycle exists.

        if(dis[u]!=INT_MAX && dis[v] > dis[u] + wt)
            return {};
    }
    return dis; 
}