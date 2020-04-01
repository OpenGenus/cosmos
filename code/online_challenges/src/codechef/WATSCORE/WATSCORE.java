import java.util.*;
import java.lang.*;
import java.io.*;

class watscore
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
	    int T=sc.nextInt();
	    while(T>0)
	    {
             int N=sc.nextInt();
	        int sum=0;
	        int P[]=new int[N];
	        int S[]=new int[N];
	        int max[]=new int[11];
	        for(int i=0;i<N;i++)
	        {
	            P[i]=sc.nextInt();
	            S[i]=sc.nextInt();
	        }
	        for(int i=0;i<N;i++)
	        {
	            if(S[i]>max[P[i]-1])
	            max[P[i]-1]=S[i];
	        }
	        for(int i=0;i<8;i++)
	        {
	            sum+=max[i];
	        }
	        System.out.println(sum);
	    T--;
	    }
	}
}
