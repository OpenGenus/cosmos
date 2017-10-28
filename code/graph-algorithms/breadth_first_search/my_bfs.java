

import java.util.LinkedList;
import java.util.Queue;
import java.util.*;

public class bfs {
    private int V;
    private LinkedList<Integer> adj[];
    bfs(int v)
    {
        V = v;
        adj = new LinkedList[v];
        for (int i=0; i<v; ++i)
            adj[i] = new LinkedList();
    }
    void addEdge(int v,int w)
    {
        adj[v].add(w);
    }
       void bfsimp(int s,int n){
//initialization
        Queue<Integer> queue=new LinkedList<Integer>();
        int level[]=new int[n];
        int parent[]=new int[n];
        Arrays.fill(level,-1);
        Arrays.fill(parent,-1);
       //start from exploring vertex x; level[s] set to 0
       level[s]=0;
        queue.add(s);

        while(!queue.isEmpty()){
            s = queue.poll();
            System.out.print(s+" ");
            Iterator<Integer> i = adj[s].listIterator();
            while (i.hasNext())
            {
                int k = i.next();
                if (level[k]==-1)
                {
                    level[k]=1+level[s];
                    parent[k]=s;
                    queue.add(k);
                }
            }
        }
    }
    public static void main(String args[])
    {
        bfs g = new bfs(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("Following is Breadth First Traversal "+
                "(starting from vertex 2)");

        g.bfsimp(2,4);
    }
}
