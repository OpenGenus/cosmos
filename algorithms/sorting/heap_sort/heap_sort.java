import java.util.*;
/*
 * Part of Cosmos by OpenGenus Foundation
*/
public class HeapSort {
    
    public static void main(String[] args) {
        // array used for testing
        int[] a = {5, 11, 1234, 2, 6};
        System.out.println(Arrays.toString(a));
        sort(a);
        System.out.println(Arrays.toString(a));
    }

    public static void sort(int[] a) {
        int n = a.length;
        // create the heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(a, n, i);
 
        // extract element from the heap
        for (int i=n-1; i>=0; i--)
        {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
 
            // rebuild the heap
            heapify(a, i, 0);
        }
    }

    public static void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;   

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;
 
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
 
        // If largest is not root
        if (largest != i)
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
 
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
}
