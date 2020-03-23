import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Guessnum {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int t = s.nextInt();
        while (t-- > 0) {
            long a = s.nextLong();
            long m = s.nextLong();
            ArrayList<Long> arrLL = new ArrayList<>();
            ArrayList<Long> newarrLL = new ArrayList<>();

            // finding factors of m
            for (long i = 1; i <= Math.sqrt(m); i++) {
                if (m % i == 0) {
                    if (m / i == i) {
                        // Storing all factors of m in arrLL
                        arrLL.add(i);
                    } else {
                        arrLL.add(i);
                        arrLL.add((m / i));
                    }
                }
            }

            int count = 0;
            // f is number of factors
            for (long f : arrLL) {

                if ((f - 1) % a == 0) {
                    long q = (f - 1) / a;
                    long d = m / f;
                    long n = q * d;

                    if (n != 0) {
                        newarrLL.add(n);
                        count++;
                    }
                }
            }
            System.out.println(count);
            Collections.sort(newarrLL);
            for (long i : newarrLL) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
/*
TEST CASE
INPUT
3
3 35
5 50
4 65

OUTPUT
1
10
0

3
13 15 16
*/

