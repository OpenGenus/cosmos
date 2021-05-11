import java.io.*;
import java.util.*;

class Slab {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        int a = 12500;
        int b = 25000;
        int c = 37500;
        int d = 50000;
        int e = 62500;

        while (t-- > 0) {
            long n = s.nextLong();
            long ans = 0;
            if (n <= 250000) {
                System.out.println(n);
            } else {
                if (n >= 250001 && n <= 500000) {
                    long div = (long) ((n - 250000) * 0.05);
                    System.out.println(n - div);
                } else if (n >= 500001 && n <= 750000) {
                    long div = (long) ((n - 500000) * 0.1);
                    System.out.println(n - a - div);
                } else if (n >= 750001 && n <= 1000000) {
                    long div = (long) ((n - 750000) * 0.15);
                    System.out.println(n - a - b - div);
                } else if (n >= 1000001 && n <= 1250000) {
                    long div = (long) ((n - 1000000) * 0.2);
                    System.out.println(n - a - b - c - div);
                } else if (n >= 1250001 && n <= 1500000) {
                    long div = (long) ((n - 1250000) * 0.25);
                    System.out.println(n - a - b - c - d - div);
                } else if (n > 1500000) {
                    long f = (long) ((n - 1500000) * 0.3);
                    System.out.println(n - a - b - c - d - e - f);
                }
            }
        }
    }
}

/*
TEST CASE

INPUT
2
600000
250000

OUTPUT
577500
250000
*/

