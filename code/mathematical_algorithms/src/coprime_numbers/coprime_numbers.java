import java.io.InputStreamReader;
import java.util.Scanner;

class CoprimeNumbers {
	public static int gcd(int num1 , int num2) {
		int tmp = 1;
		while(tmp != 0) {
			tmp = num1 % num2;
			if(tmp == 0)
				return num2;
			num1 = num2;
			num2 = tmp;
		}
		return num2;
	}
	public static void main(String []args) {
		Scanner in = new Scanner(new InputStreamReader(System.in));
		System.out.println("Enter 2 numbers: ");
		int num1 = in.nextInt();
		int num2 = in.nextInt();
		if(gcd(num1, num2) == 1)
			System.out.println("The entered numbers are Co-Prime numbers");
		else
			System.out.println("The entered numbers are not Co-Prime numbers");
		in.close();
	}
}
