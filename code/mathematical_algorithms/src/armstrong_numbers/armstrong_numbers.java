import java.util.Scanner;

class Main { //Main function
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);//Input from keyboard through Scanner class in Java

		System.out.println("Enter a 3-digit number : ");//Asking from user to enter a 3-digit number
		int number = in.nextInt();//Reading Integer input through keyboard using method
		int a = number % 10;//Getting remainder for number at unit place
		int b = (number / 10) % 10;//Number for ten's place
		int c = number / 100;//Number for hundretth place

		if ((a*a*a + b*b*b + c*c*c) == number) {//Condition to check
			System.out.println(number + " is a armstrong number.");//Output return 
		}
		else {
			System.out.println(number + " is not a armstrong number.");//Output return 
		}
		in.close();//Closing Scanner class
	}
}
