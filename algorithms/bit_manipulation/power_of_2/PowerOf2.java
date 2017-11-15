import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class PowerOf2{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();

		if(((num & (num-1))==0) && (num != 0))
			System.out.println("Yes, the number is a power of 2");
		else
			System.out.println("No, the number is not a power of 2");
	}
}