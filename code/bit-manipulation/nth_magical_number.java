
import java.util.Scanner;

//Part of Cosmos by OpenGenus Foundation
public class nth_magical_number {

	public static int nthMagicNo(int n)
	 {
	     int pow = 1, answer = 0;
	 
	     // Go through every bit of n
	     while (n!=0)
	     {
	         pow = pow*5;
	 
	         // If last bit of n is set
	         if ((n & 1)!=0)
	             answer += pow;
	 
	         // proceed to next bit
	         n >>= 1;  // or n = n/2
	     }
	     return answer;
	 }
	
	public static void main(String[] args) {
		Scanner scn=new Scanner(System.in);
		int n=scn.nextInt();
		System.out.println("nath magic number is " + nthMagicNo(n));
	}
	
}
