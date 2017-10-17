import java.util.*;
import java.lang.*;
import java.io.*;
 
class GraphClosure
{
    final static int V = 4; //Number of vertices in a graph
    
    void transitiveClosure(int graph[][]) {
    
        int reach[][] = new int[V][V];
        int  i, j, k;
 
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                reach[i][j] = graph[i][j];
                
        for (k = 0; k < V; k++) {
            for (i = 0; i < V; i++) {
                for (j = 0; j < V; j++) {
                    reach[i][j] = (reach[i][j]!=0) ||
                             ((reach[i][k]!=0) && (reach[k][j]!=0))?1:0;
                }
            }
        }
 
        printSolution(reach);
    }
 
    void printSolution(int reach[][]) {
        System.out.println("Following matrix is transitive closure" + " of the given graph");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                System.out.print(reach[i][j]+" ");
            System.out.println();
        }
    }
 
    public static void main (String[] args) {
         int graph[][] = new int[][]{ {1, 1, 0, 1},
                                      {0, 1, 1, 0},
                                      {0, 0, 1, 1},
                                      {0, 0, 0, 1}
                                    };
 
         GraphClosure g = new GraphClosure();
         g.transitiveClosure(graph);
    }
}
