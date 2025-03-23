import java.util.*;
public class BinarySearch {
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[]args) {
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = sc.nextInt();
        int ele = sc.nextInt();
        int res = BinarySearch(arr,ele);
        if(res == -1)
            System.out.println("Not Found");
        else
            System.out.println("Fount at = "+res);
    }
    static int BinarySearch(int [] arr, int ele) {
        int l = 0;
        int r = arr.length -1;
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(arr[mid] == ele)
                return mid;
            if(arr[mid] < ele)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
}
