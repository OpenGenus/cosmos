import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for(int i = 0; i < V+1; i++)
                list.add(i, new ArrayList<Integer>());
            for(int i = 0; i < E; i++)
            {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
            }
            if(new Solution().isCyclic(V, list) == true)
                System.out.println("1");
            else System.out.println("0");
        }
    }
}



class Solution {
    public boolean isCyclic(int N, ArrayList<ArrayList<Integer>> adj) {
        int topo[] = new int[N]; 
        int indegree[] = new int[N]; 
        for(int i = 0;i<N;i++) {
            for(Integer it: adj.get(i)) {
                indegree[it]++; 
            }
        }
        
        Queue<Integer> q = new LinkedList<Integer>(); 
        for(int i = 0;i<N;i++) {
            if(indegree[i] == 0) {
                q.add(i); 
            }
        }
        int cnt = 0;
        while(!q.isEmpty()) {
            Integer node = q.poll(); 
            cnt++; 
            for(Integer it: adj.get(node)) {
                indegree[it]--; 
                if(indegree[it] == 0) {
                    q.add(it); 
                }
            }
        }
        if(cnt == N) return false; 
        return true; 
    }
}