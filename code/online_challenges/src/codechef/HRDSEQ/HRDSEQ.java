//Part of cosmos by OpenGenus

import java.util.*;
import java.lang.*;
import java.io.*;

class hardseq
{
	public static void main (String[] args) throws java.lang.Exception
	{   
        Scanner sc=new Scanner(System.in);
	    int A[]=new int[128];
	    A[0]=0;
	    A[1]=0;
	    A[2]=1;
	    int j=0;
	    for(int i=3;i<128;i++)
	    {
	        j=i-2;
	        while(j>0)
	        {
	            if(A[j]==A[i-1])
	            {
	                A[i]=i-j-1;
	                break;
	            }
	            j--;
	        }
	        if(j==0)
	        A[i]=0;
	    }
        int T=sc.nextInt();
        while(T>0)
        { 
            int N=sc.nextInt();
            int temp=A[N-1];
            int count=0;
            for(int i=0;i<N;i++)
            {
                if(A[i]==temp)
                count++;
            }
            System.out.println(count);
            T--;
        }
	}
}
