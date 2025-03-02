import java.util.Scanner;

class Dynamo {
    public static void main (String[] args)
    {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t-- > 0){
            int n = s.nextInt();
            long a = s.nextLong();

            long S = (long)(2 * Math.pow(10, n)) + a;
            System.out.println(S);

            long b = s.nextLong();

            long c = (long)(Math.pow(10, n)) - b;
            System.out.println(c);

            long d = s.nextLong();

            long e = S - a - b - c - d;
            System.out.println(e);

            int ans = s.nextInt();
            if (ans == -1) break;

            System.out.println();
            System.out.flush();
        }
    }
}

/*
EXAMPLE

You             Grader
                1
                2
                10
50
                10
12
                10
8
                1

*/

