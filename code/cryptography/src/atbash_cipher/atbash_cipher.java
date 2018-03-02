import java.util.Scanner;

public class atbash_cipher {
	
	public static void main( String[] args) {
	
		Scanner scan = new Scanner(System.in);
	
		String newStr,s;
	 	char alpha;
	
		s = scan.nextLine();
	
		newStr = s;
	
	        // Converting string to character array
		char[] n = newStr.toCharArray();
	
		for(int i = 0; i < s.length(); i++) {
			alpha = s.charAt(i);
		
			if(Character.isUpperCase(alpha) == true ) { 
				n[i] = (char) ('Z' - ( alpha - 'A' ));
		
			} else if(Character.isLowerCase(alpha) == true ) {
				n[i] = (char) ( 'z' -( alpha - 'a' ));
		
			} else { 
				n[i] = alpha;
		      	}
	 	}
		// Converting character array back to string
		String cipher = new String(n);
	
		System.out.println(cipher);
	}
}
