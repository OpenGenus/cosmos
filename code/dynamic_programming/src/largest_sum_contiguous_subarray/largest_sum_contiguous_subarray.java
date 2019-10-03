/* Part of Cosmos by OpenGenus Foundation */ 

import java.util.Scanner;

public class Max_subarray_problem {

    public static void main(String[] args) {

        System.out.println(new int[] {-3,  2, -1,  4, -5}, 0, 4); // Expected output: 5
        System.out.println(new int[] {-1, -2, -3, -4, -5}, 0, 4); // Expected output: -1
    }

    private static int findmaxsum(int[] a, int l, int h) {
        int max;
        if(l==h)
            return a[l];
        else
        {
            int mid = (l + h) / 2;

            int leftmaxsum  = findmaxsum(a, l, mid);
            int rightmaxsum = findmaxsum(a , mid + 1, h);
            int crossmaxsum = findcrosssum(a, l, mid, h);
       
            max = Math.max(Math.max(leftmaxsum, rightmaxsum), crossmaxsum);
        }
        return max;
      
    }

    private static int findcrosssum(int[] a, int l, int mid, int h) {

        int leftsum = Integer.MIN_VALUE;
        int lsum = 0;
        for(int i = mid; i >= l; i--)
        {
            lsum += a[i];
            if(lsum > leftsum)
                leftsum = lsum;
        }
        int rightsum = Integer.MIN_VALUE;
        int rsum = 0;
        for(int j = mid + 1; j <= h; j++)
        {
            rsum += a[j];
            if(rsum > rightsum)
                rightsum = rsum;
        }
        return rightsum + leftsum;
    }
    
}
