//part of cosmos by OpenGenus

import java.util.*;
import java.lang.*;
import java.io.*;

class proxyc
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		while(T-->0)
		{
		    int dec=sc.nextInt();
		    sc.nextLine();
		    String s=sc.nextLine();
		    int count=0;
		    int c=0;
		    for(int i=0;i<s.length();i++)
		    {
		        if(s.charAt(i)=='P')
		        count++;
		    }
            double D=dec;
		    if(((count/D)*100)>=75)
		        System.out.println("0");
		    else
		    {
		        for(int i=2;i<s.length()-2;i++)
		        {
		            char a=s.charAt(i-2);
		            char b=s.charAt(i-1);
		            char cc=s.charAt(i+1);
		            char d=s.charAt(i+2);
		            if(s.charAt(i)=='A')
		            {
		                if(((a=='P')||(b=='P'))&&((cc=='P')||(d=='P')))
		                {
		                    count++;
		                    c++;
		                    if(((count/D)*100)>=75)
		                    {   
                                System.out.println(c);
		                        break;
		                   
		                    }
		                }
		 
		            }
		        }
		        if(((count/D)*100)<75)
		            System.out.println("-1");
		    }
		}
	}
}
