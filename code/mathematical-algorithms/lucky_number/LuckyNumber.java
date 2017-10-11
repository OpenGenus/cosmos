import java.util.*;
import java.lang.*;
import java.io.*;

class LuckyNumber
{
	static int counter=2; 		//counter to delete the counter'th term

	public static void main (String[] args)		//driver function
	{

		Scanner scr=new Scanner(System.in);

		int num;

		System.out.print("Enter a number: ");

		num=scr.nextInt();

		System.out.println();

		if(luckynumber(num))
			System.out.println(num+" is a lucky number");

		else
			System.out.println(num+" is not a lucky number");

	}

	public static boolean luckynumber(int n)		//To check if a number is lucky
	{
		
		if(counter>n)
			return true;

		if(n%counter==0)
			return false;

		n-=n/counter;		

		counter++;

		return luckynumber(n);

	}
}
