import java.util.Scanner;
import java.util.Stack;
// Part of Cosmos by OpenGenus Foundation
public class TopologicalSort {
    private Stack<Integer> stack;

    public TopologicalSort()
    {
        stack = new Stack<Integer>();
    }
   // adj below refers to adjacency matrix and s refers to start
    public Integer [] topological(int adj[][], int s) throws NullPointerException
    {
        int len = adj[s].length - 1; //Length of starting row
        Integer[] aux = new Integer[len + 1]; //It will store the final result
        int pos = 1;
        int j ;
        int visited[] = new int[len + 1]; // To store the visited status
        int ele = s;
        int i = s;
        visited[s] = 1;
        stack.push(s);

        while (!stack.isEmpty())
        {
            ele = stack.peek();
            while (i <= len)
            {
                if (adj[ele][i] == 1 && visited[i] == 1)
                {
                    if (stack.contains(i))
                    {
                        return null;// Topo sort not possible
                    }
                }
                if (adj[ele][i] == 1 && visited[i] == 0)
                {
                    stack.push(i);
                    visited[i] = 1;
                    ele = i;
                    i = 1;
                    continue;
                }
                i++;
            }
            j = stack.pop();
            aux[pos++] = j;
            i = ++j;
        }
        return aux;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of vertices :");
        int nodes=sc.nextInt();
        int adj[][]=new int[nodes+1][nodes+1]; //Adjacency matrix
        for (int i=1;i<=nodes;i++)
        {
            for (int j=1;j<=nodes;j++)
            {
                adj[i][j]=sc.nextInt();
            }
        }
       System.out.println("Enter the initial point");
        int s=sc.nextInt();
        TopologicalSort ob=new TopologicalSort();
        System.out.println("The topological order is :");
        Integer[] nums=ob.topological(adj,s);
        if (nums!=null) {
            for (int k = nums.length - 1; k >= 0; k--)
                System.out.print(((nums[k]!=null)?nums[k]:" ") + " ");
            System.out.println();
        }
        else
        {
            System.out.println("Topological Order not possible .");
        }
        sc.close();
    }
}
