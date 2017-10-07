import java.util.Scanner;
// Part of Cosmos by OpenGenus Foundation
public class Factorial {
    public static void main(String args[]) {
        Scanner stdin = new Scanner(System.in);
        Factorial obj = new Factorial();
        System.out.println("Enter a number");
        int n = stdin.nextInt();
        System.out.println("The factorial is " + obj.fact(n));
    }
    
    long fact(int n) {
        if(n == 0) {
            return 1;
        } else {
            return ((long)n * fact(n-1));
        }
    }
}
