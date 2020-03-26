import java.util.*;
import java.lang.*;
import java.io.*;

class Test
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
		int t, n, id = 0, cid = 0, ans;
		t = s.nextInt();
		
		for(; t > 0; t--)
		{
		    n = s.nextInt();
		    ans = 0;
		    for(int i = 0; i < n; i++)
		    {
		        id = s.nextInt();
		        cid = s.nextInt();
				ans += id - cid;
		    }
		    System.out.println(ans);
		}
	}
}
