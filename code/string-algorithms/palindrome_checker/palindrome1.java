import java.util.Scanner;

public class Palindrome {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String str = s.nextLine();
		char[] starr = str.toCharArray();
		boolean isPalindrome = true;
		for (int i = 0; i < starr.length / 2; i++) {
			if (starr[i] != starr[starr.length - 1 - i]) {
				isPalindrome = false;
				break;
			}
		}

		if (isPalindrome) {
			System.out.println("It is a palindrome");
		} else {
			System.out.println("It is not a palindrome");
		}
		s.close();
	}

}
