import java.io.*;
import java.lang.*;

class Palindrome{
	public static void main(String args[]){
		String s = "sos";

		String reverse = new StringBuffer(s).reverse().toString();   //Convert string to StringBuffer, reverse it and convert StringBuffer into String using toString()

		if(s.equals(reverse)){    //Compares s and reverse of s and if they are same print Yes else print No
		System.out.println("Yes");
		}
		else
		System.out.println("No");
	}
}