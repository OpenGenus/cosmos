  
// Part of Cosmos by OpenGenus
import java.util.*;
import java.lang.*;
import java.io.*;

class twogrs
{
	public static void main (String[] args) throws java.lang.Exception
	{ Scanner sc=new Scanner(System.in);
	int T=sc.nextInt();
	while(T>0)
		{
	    	int A=sc.nextInt();
	    	int B=sc.nextInt();
	    	int C=sc.nextInt();
	    	int s=(A*1)+(B*2)+(C*3);
	    	if(s%2!=0)
	    		System.out.println("NO");
	    	else
	    	{
	    		if(A==0&&B%2!=0&&C==0)
	    			System.out.println("NO");
	        	else if(A==0&&B==1&C%2==0)
	        		System.out.println("NO");
	        	else if(A==1&&B==0&&C%2!=0)
	        		System.out.println("NO");
	        	else
	        		System.out.println("YES");
	    	}
		T--;
		}
	}
}
