// Part of Cosmos by OpenGenus

import java.util.*;
import java.lang.*;
import java.io.*;

class giftsrc
{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner sc=new Scanner(System.in);
	int T=sc.nextInt();
	while(T-->0)
	{   int x=0;
	    int y=0;
	    int n=sc.nextInt();
      	sc.nextLine();
	    String s=sc.nextLine();
	    char c=s.charAt(0);
	   if(c=='L')
	     {
	         x-=1;
	     }
	     else if(c=='R')
	     {
	         x+=1;
	     }
	     else if(c=='U')
	     {
	         y+=1;
	     }
	     else y-=1;
	    for(int i=1;i<s.length();i++)
	    { if(s.charAt(i)!=c)
	     {
	         if(s.charAt(i)=='L'&&c!='R')
	     {
	         x-=1;
	           c=s.charAt(i);
	     }
	     else if(s.charAt(i)=='R'&&c!='L')
	     {
	         x+=1;
	         c=s.charAt(i);
	     }
	     else if(s.charAt(i)=='U'&&c!='D')
	     {
	         y+=1;
	         c=s.charAt(i);
	     }
	     else if(s.charAt(i)=='D'&&c!='U')
	     {y-=1;
	     c=s.charAt(i);
	     }
	     }
	    }
	    	System.out.println(x+" "+y);
	}
	}

}
