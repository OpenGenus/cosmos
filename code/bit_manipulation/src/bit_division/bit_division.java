import java.util.Scanner;
// Part of Cosmos by OpenGenus Foundation
class BitDivision
{
	static int division(int divident, int divisor)
	{
		int curr=1;
		int result=0;	
		if ( divisor >divident)
    	    return 0;

    	else if ( divisor ==divident)
    	    return 1;

    	while (divisor <divident) 
    	{
    	    divisor <<= 1;
    	    curr <<= 1;
    	}

    	divisor >>= 1;
    	curr >>= 1;

  	  	while (curr!=0) 
  	  	{
        	if (divident >= divisor) 
        	{
        	   divident -= divisor;
           	 	result |= curr;
        	}
        	curr >>= 1;
        	divisor >>= 1;
    	}
    	return result;
	}

	public static void main(String[]args)
	{
		Scanner scan=new Scanner(System.in);
		//a -> represents divident
		int a=scan.nextInt();
		//b -> represents divisor
		int b=scan.nextInt();
		System.out.println(division(a,b));
	}
}
