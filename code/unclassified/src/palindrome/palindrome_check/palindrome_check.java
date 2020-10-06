/* checks whether a given string is palindrome or not */
import java.util.Scanner;

public class palindrome_check {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String word = scan.nextLine();
		if(word.equals(reverse(word))) 
			System.out.println("yes it's a string");
		else
			System.out.println("no itsn't a string");
	}
	// reverses the given string
	public static String reverse(String word) {
		String new_word = "";
		if(word.length() == 1)
			new_word = word;
		else {
			for(int i = word.length() - 1; i >= 0; i--)
				new_word += word.charAt(i);
		}
		return new_word;
	}
}
