//This is a java program to sort numbers using Stooge Sort
import java.util.Random;
 
public class StoogeSort 
{
 
    public static int N = 20;
    public static int[] sequence = new int[N];
 
    public static int[] stoogeSort(int[] L, int i, int j) 
    {
        if (L[j] < L[i]) 
        {
            int swap = L[i];
            L[i] = L[j];
            L[j] = swap;
        }
        if ((j - i + 1) >= 3) 
        {
            int t = (j - i + 1) / 3;
            stoogeSort(L, i, j - t);
            stoogeSort(L, i + t, j);
            stoogeSort(L, i, j - t);
        }
        return L;
    }
 
    public static void printSequence(int[] sorted_sequence) 
    {
        for (int i = 0; i < sorted_sequence.length; i++)
            System.out.print(sorted_sequence[i] + " ");
    }
 
    public static void main(String[] args) 
    {
        Random random = new Random();
        System.out
                .println("Sorting of randomly generated numbers using STOOGE SORT");
 
        for (int i = 0; i < N; i++)
            sequence[i] = Math.abs(random.nextInt(1000));
 
        System.out.println("\nOriginal Sequence: ");
        printSequence(sequence);
 
        System.out.println("\nSorted Sequence: ");
        printSequence(stoogeSort(sequence, 0, sequence.length - 1));
    }
}
