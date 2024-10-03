import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the Number:"); // taking input
        int n = input.nextInt();
        int output = fib(n);
        System.out.println("Nth fibonacci no. is: " + output);
    }

    public static int fib(int n) {
        int[] fibNumber = new int[n + 1]; // creating an array to store the outputs
        fibNumber[0] = 0;
        fibNumber[1] = 1;
        for (int i = 2; i <= n; i++) {
            fibNumber[i] = fibNumber[i - 1] + fibNumber[i - 2]; // storing outputs for further use
        }
        return fibNumber[n];
    }
}
