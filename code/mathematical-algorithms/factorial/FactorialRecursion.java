import java.util.Scanner;
import java.math.BigInteger;

public class FactorialRecursion {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		System.out.print("Enter a number> ");
		int n = in.nextInt();

		System.out.println(n + "! = " + recursiveFactorial(n));
	}

	public static BigInteger recursiveFactorial(int n) {
		if (n <= 1)
			return BigInteger.ONE;

		BigInteger next = BigInteger.valueOf(n);
		return next.multiply(recursiveFactorial(n - 1));
	}
}
