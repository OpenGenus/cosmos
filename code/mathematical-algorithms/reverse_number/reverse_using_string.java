import java.util.*;

public class Reverse_Using_String
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter a number to reverse: ");
		// Input number as string and pass it to StringBuffer
		StringBuffer num = new StringBuffer(scan.next());
		//Use the .reverse() method of StringBuffer class to reverse the number
		System.out.format("Reverse of the number is: %s", num.reverse());
	}
}