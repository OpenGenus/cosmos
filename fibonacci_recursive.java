//Recursive Fibonacci Algorithm
import java.util.Scanner;

public class fibonacci_recursive { 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("How Fibonacci terms would you like to know? ");
        int n = scanner.nextInt();  // Number of Fibonacci terms to generate
        System.out.println("The first " + n + " terms in the Fibonacci sequence are: ");
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacci(i) + " ");
        }
        System.out.println();
    }

    // Recursive method to calculate the nth Fibonacci number
    public static int fibonacci(int n) {
        if (n <= 1) {
            //Base Case
            return n;
        }
        //Recursive Call
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
}