import java.util.*;
public class InsertionSort {
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[]args) {
        int n = sc.nextInt();
        int arr [] = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = sc.nextInt();
        InsertionSort(arr,n);
    }

    static  void InsertionSort (int [] arr, int n) {
        for(int i=1; i<n; i++) {
            int key = arr[i];
            int j = i-1;

            while(j>=0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
        for(int i=0; i<n; i++)
            System.out.print(arr[i]+" ");
    }
}
