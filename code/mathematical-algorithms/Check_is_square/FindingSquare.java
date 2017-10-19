// Part of Cosmos by OpenGenus Foundation 

import java.util.Scanner;

public class CheckisSquare{	
    private static boolean checkIsSquare(int n){
        if (n < 0) {
            return false;
        } else {
            int start = 0;
            int end = n;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                long val = (long) mid * (long) mid;
                if (val == n)
                    return true;
                else if (val < n)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.print("Please enter number: ");
        Scanner enterN = new Scanner(System.in);
        int n = enterN.nextInt();
        if (checkIsSquare(n)) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }
    }
}
