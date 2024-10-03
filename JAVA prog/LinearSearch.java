import java.util.*;
public class LinearSearch {
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[]args) {
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = sc.nextInt();
        int ele = sc.nextInt();
        for(int i=0; i<n; i++) {
            if(ele == arr[i])
                System.out.println("Element found at "+ (i+1) + " position");
        }
    }
}
