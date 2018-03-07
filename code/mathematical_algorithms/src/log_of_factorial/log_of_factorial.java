import java.io.InputStreamReader;
import java.util.Scanner;

class LogOfFactorial {
	public static double logOfFactorial(int num) {
		double ans = 0;
		for(int i = 1; i <= num; ++i)
			ans += Math.log(i);
		return ans;
	}
	public static void main(String []args) {
		Scanner in = new Scanner(new InputStreamReader(System.in));
		System.out.println("Enter a number: ");
		int num = in.nextInt();
		System.out.println("Log of Factorial of " + num + " is " + logOfFactorial(num));
		in.close();
	}
}
