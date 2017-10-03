/* Part of Cosmos by OpenGenus Foundation */
/*
Bellman Ford algorithm implementation in Java
 */
//Edge for Graph
class Edge{
    int src, dest, weight;
    Edge(){
        src = 0;
        dest = 0;
        weight = 0;
    }
}

//Graph data structure
class Graph {
    int noOfVerts,noOfEdge;
    Edge edge[];
    Graph(int v, int e){
        noOfVerts = v;
        noOfEdge = e;
        edge = new Edge[e];
        for (int i=0;i<e;i++)
            edge[i] = new Edge();
    }

}
class BellmanFord{
    //The function tp find shortest distances from src to all nodes
    int[] doBellmanFord(Graph graph, int src){
        int noOfVerts = graph.noOfVerts, noOfEdge = graph.noOfEdge;
        int distances[] = new int[noOfVerts];

        //Initialize distances
        for (int i=0;i<noOfVerts;i++)
            distances[i] = Integer.MAX_VALUE;
        distances[src] = 0; //distance from src to src is 0

        for(int i=1;i<noOfVerts;i++){
            for(int j=0;j<noOfEdge;j++){
                int m = graph.edge[j].src;
                int n = graph.edge[j].dest;
                int weight = graph.edge[j].weight;
                if(distances[m]!=Integer.MAX_VALUE &&
                        distances[m]+weight<distances[n])
                    distances[n] = distances[m]+weight;
            }
        }
        //Checking negetive weight cycle
        for(int i=0;i<noOfEdge;i++){
            int m = graph.edge[i].src;
            int n = graph.edge[i].dest;
            int weight = graph.edge[i].weight;
            if(distances[m]!=Integer.MAX_VALUE &&
                    distances[m]+weight<distances[n])
                System.out.println("Graph contains negetive weight cycle");
        }
        return distances;
    }
}
