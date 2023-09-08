/* Part of Cosmos by OpenGenus Foundation */

import java.util.Random;
import java.util.Scanner;
 
public class Kth_Smallest_Element
{
    public static int N = 20;
    public static int[] A = new int[N];
 
    public static void swap(int dex1, int dex2) 
    {
        int temp = A[dex1];
        A[dex1] = A[dex2];
        A[dex2] = temp;
    }
 
    public static int partition(int start, int end) 
    {
        int i = start + 1;
        int j = i;
        int pivot = start;
        for (; i < end; i++) 
        {
            if (A[i] < A[pivot]) 
            {
                swap(i, j);
                j++;
            }
        }
        if (j <= end)
            swap(pivot, (j - 1));
 
        return j - 1;
    }
 
    public static void quick_sort(int start, int end, int K) {
        int part;
        if (start < end) 
        {
            part = partition(start, end);
            if (part == K - 1)
                System.out.println("kth smallest element : " + A[part]);
            if (part > K - 1)
                quick_sort(start, part, K);
            else
                quick_sort(part + 1, end, K);
        }
        return;
    }
 
    public static void main(String args[]) 
    {
        Random random = new Random();
        for (int i = 0; i < N; i++)
            A[i] = random.nextInt(1000);
 
        System.out.println("The original sequence is:  ");
        for (int i = 0; i < N; i++)
            System.out.print(A[i] + " ");
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEntering 4 as  the Kth smallest you want to find: ");
        int k = 4;
 
        quick_sort(0, N, k);
        sc.close();
    }
}
