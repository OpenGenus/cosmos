import java.io.*;
import java.lang.*;

class Palindrome{
	public static void main(String args[]){
		String s = "sos";
		String reverse = new StringBuffer(s).reverse().toString();

		if(s.equals(reverse)){
		System.out.println("Yes");
		}
		else
		System.out.println("No");
	}
}