import java.util.*;
import java.lang.*;
import java.io.*;

class Test
{    	 
	public static void main (String[] args) throws java.lang.Exception
	{    		 
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		
		while(t>0)
		{			
			t--;
			int n = s.nextInt();
			int ans = 0;
			int id = 0, cid = 0, i;
			
			for(i = 0; i < n; ++i)
			{	  
				id = s.nextInt();
				cid = s.nextInt();
				ans += id - cid;
			}
			System.out.println(ans);
		}	   
	}		
}	 
