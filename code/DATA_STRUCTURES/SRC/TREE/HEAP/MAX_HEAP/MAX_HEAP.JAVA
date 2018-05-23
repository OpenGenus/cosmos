//Part of Open Genus foundation
import java.util.Scanner;

/**
 * Created by risha on 15-10-2017.
 */
// Priority Queue binary max_heap implementation
public class MaxPQ<Key extends Comparable<Key>> {
    private Key []pq;
    private int N=0;
    private int capacity;
    public MaxPQ(int capacity)
    {
        pq= (Key[]) new Comparable[capacity+1];
        this.capacity=capacity;
    }
    public boolean isEmpty()
    {
        return N==0;
    }
    public void insertKey(Key x)
    {
        if (N+1>capacity)
            resize();
      pq[++N]=x;
      swim(N);
    }
    public int size()
    {
        return N;
    }
   /* public int getCapacity()
    {
        return this.capacity;
    }*/
    private void resize()
    {
        this.capacity=2*N;
        Key[] temp= (Key[]) new Comparable[this.capacity+1];
        for (int i=1;i<=N;i++)
            temp[i]=pq[i];
        pq=temp;
    }
    public Key delMax()
    {
        if (isEmpty())
            return null;
     Key max=pq[1];
     exch(1,N--);
        sink(1);
     pq[N+1]=null;
        return max;
    }
    private void swim(int k)
    {
     while (k>1 && less(k/2,k))
     {
         exch(k,k/2);
         k=k/2;
     }
    }
    private void sink(int k)
    {
     while (2*k<=N)
     {
         int j=2*k;
         if(j<N && less(j,j+1))j++;
         if (!less(k,j))break;
         exch(k,j);
         k=j;
     }
    }
    private boolean less(int i,int j)
    {
     return pq[i].compareTo(pq[j])<0;
    }
    private void exch(int i,int j)
    {
        Key t=pq[i];
        pq[i]=pq[j];
        pq[j]=t;
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of heap");
        int n=sc.nextInt();
        MaxPQ<Integer> pq=new MaxPQ<Integer>(n);
        for (int i=0;i<n;i++)
            pq.insertKey(sc.nextInt());
        System.out.println("Size of heap: "+pq.size());
      //  System.out.println("Capacity: "+pq.getCapacity());
        System.out.println("Maximum keys in order");
        while (!pq.isEmpty())
        {
            System.out.println(pq.delMax());
        }
        System.out.println(pq.delMax());
    }
}
