// Part of Cosmos by OpenGenus

import java.util.*;
import java.lang.*;
import java.io.*;

class sshoes
{
	public static void main (String[] args) throws java.lang.Exception
	{
        Scanner sc=new Scanner(System.in);
	    int T=sc.nextInt();
	    while(T-->0)
	    {
	        int N=sc.nextInt();
	        int K=sc.nextInt();
	        sc.nextLine();
	        String str=sc.nextLine();
	        int count[]=new int[26];
	        int flag=0;
	        for(int i=0;i<str.length();i++)
	        {
	            count[str.charAt(i)-97]++;
	        }
	        for(int i=0;i<26;i++)
	        {
                if(count[i]>0)
                {
	                if((count[i]%2==0)&&(count[i]/2>K))
	                {   flag++;
	                    break;
	                }
	                if(count[i]%2!=0)
	                {
                        flag++;
	                    break;
	                }
	            }
	        }
	    if(flag==0)
	    System.out.println("YES");
	    else
	    System.out.println("NO");
	    }
    }
}