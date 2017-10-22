// Given a binary number ( represented as a string ) find if the number is a multiple of three

import java.util.*;

public class IsMultipleOfThree {
	/* 
	**Divide the number into 4 bits ( a nibble ) and add all these nibbles. 
	**If this sum is a multiple of three then the whole number is a multiple of three.
	*/
	private static boolean isMultipleOfThree(String number) {
		int sum = 0;
		
		for(int i = 0; i < number.length(); i += 4) {
			String nibble = number.substring(i, i + 4);			
			sum += Integer.valueOf(nibble, 2);
		}

		return sum % 3 == 0;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String number = scanner.nextLine();			

		//make the length of the input string divisible by 4
		for(int i = 0; i < number.length() % 4; i++) number = '0' + number;

		System.out.println(isMultipleOfThree(number));

		scanner.close();
	} 
}
