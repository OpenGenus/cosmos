//part of cosmos by OpenGenus

import java.util.*;
import java.lang.*;
import java.io.*;

class cog
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
	    int T=sc.nextInt();
	    while(T>0)
	    { 
            int n=sc.nextInt();
	        int arr[]=new int[n];
	        for(int i=0;i<n;i++)
	            arr[i]=sc.nextInt();
	        int max=arr[0];
	        for(int i=1;i<n;i++)
	        {    if(arr[i]>max)
	                max=arr[i];
                System.out.println(max);
            }
	    T--;
	    }
	}
}
