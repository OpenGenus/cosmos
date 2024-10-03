// Brian Kernighan Algorithm is an algorithm to count the number of set bits in binary representation of a number.

import java.util.*;
public class Main
{  
	
	static int countSetBits( int n )
   {   
       if ( n == 0 )
       return 0 ;
       else 
       return 1 + countSetBits ( n & ( n - 1 ) ) ;
   }
	
	public static void main(String[] args) 
	{
		
		Scanner sc = new Scanner( System.in ) ;
		int number ;
		 number = sc.nextInt();
		 System.out.println( countSetBits( number ) );
	}
}
/*
Input - number=9
Output - 2 
Explanation - Binary representation of 9 is 1001 has 2 set bits. */
