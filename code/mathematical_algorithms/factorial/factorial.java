import java.util.Scanner;
// Part of Cosmos by OpenGenus Foundation
public class Factorial {
    public static void main(String args[]) {
        System.out.print("Enter a number: ");
        Scanner enterNum = new Scanner(System.in);
        int n = enterNum.nextInt();
        System.out.println("Factorial is: " + factorial(n));
    }
    
    private static BigInteger factorial(int n) {
        BigInteger ret = BigInteger.ONE;
        for (int i = 1; i <= n; ++i) {
            ret = ret.multiply(BigInteger.valueOf(i));
        }
        return ret;
    }
}
