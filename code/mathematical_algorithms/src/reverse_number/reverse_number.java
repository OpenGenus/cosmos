import java.util.*;

public class Reverse
{
	public static Scanner scr=new Scanner(System.in);  //Scanner object to take input

	public static void main(String[] args)  //Main function
	{
		int num;

		System.out.print("Enter a number: ");

		num=scr.nextInt();		//Number input

		System.out.println();

		int reverse=0;		//To store the reverse of a number

		for(int i=num;i>0;i/=10)
		{
			int dig=i%10;

			reverse=reverse*10+dig;
		}

		System.out.println("Reverse of the number "+num+" is: "+reverse);
	}
}
