//Program to find whether a string is a pallindrome or not

import java.util.Scanner;
public class pallindrome_string {
	
	// Reverse a given string
	public static String pallindrome(String str) {
		String str1  = "";
		for (int i = str.length()-1; i>=0;i --) {
			str1 = str1 + str.charAt(i);
		}
		return str1;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a string");
		String str = s.nextLine();
		String strrev = pallindrome(str);
		
		// Comparing 2 strings to find if input string is pallindrome or not
		if(str.equals(strrev)) {
			System.out.println("String entered is palindrome!");
		}
		else {
			System.out.println("String entered is not a palindrome!");
		}
	}
}

/*
Test cases
 
Enter a string
hello
String entered is not a palindrome!

Enter a string
metem
String entered is palindrome!
*/
