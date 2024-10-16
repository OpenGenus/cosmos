import java.io.*;
public class example 
{ 
	public static void main(String[] args) 
	{ 
		try
		{   int n=6;
			System.out.print("a"); 
			int val = n / 0; 
			throw new IOException(); 
		} 
		catch(EOFException e) 
		{ 
			System.out.printf("b"); 
		} 
		catch(ArithmeticException e) 
		{ 
			System.out.printf("c"); 
		}
		catch(IOException e) 
		{ 
			System.out.printf("d"); 
		} 
		catch(Exception e) 
		{ 
			System.out.printf("e"); 
		} 
	} 
}