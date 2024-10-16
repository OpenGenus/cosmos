import java.util.Scanner;

class Hardcash {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        while (t-- > 0) {
            int n = s.nextInt();
            int k = s.nextInt();
            int[] arr = new int[n];

            //input
            for (int i = 0; i < n; i++) {
                arr[i] = s.nextInt();
            }

            int bag = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] % k == 0) {
                    continue;
                } else {
                    int step = arr[i] % k;
                    if (k - step <= bag) {
                        bag -= (k - step);
                    } else {
                        bag += step;
                    }
                }
            }
            System.out.println(bag);
        }
    }
}

/*
TEST CASE
2
5 7
1 14 4 41 1
3 9
1 10 19

OUTPUT
5
3
*/

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

