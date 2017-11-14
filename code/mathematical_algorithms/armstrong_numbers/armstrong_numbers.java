import java.util.Scanner;

class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);

		System.out.println("Enter a 3-digit number : ");
		int number = in.nextInt();
		int a = number % 10;
		int b = (number / 10) % 10;
		int c = number / 100;

		if ((a*a*a + b*b*b + c*c*c) == number) {
			System.out.println(number + " is a armstrong number.");
		}
		else {
			System.out.println(number + " is not a armstrong number.");
		}
		in.close();
	}
}