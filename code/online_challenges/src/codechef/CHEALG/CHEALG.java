// Part of Cosmos by OpenGenus
import java.util.*;
import java.lang.*;
import java.io.*;
class chealg
{
	public static void main (String[] args) throws java.lang.Exception
	{Scanner sc=new Scanner(System.in);
	int T=sc.nextInt();
	while(T>0)
	{ String s=sc.next();
	String str="";
	int l=s.length();
	int count=1;
for(int i=0;i<l;i++)
{   char c=s.charAt(i);
    if(l==1)
	str+=c+"1";

else if(i!=l-1)
	{
	    char a=s.charAt(i+1);
	    if(a==c)
	    count++;
	    else
	 {   str+=c+String.valueOf(count);
	    count=1;
	 }
	}
	else
	{
	      char b=s.charAt(i-1);
	    if(b==c)
	     str+=c+String.valueOf(count);
	    else
	 {   str+=c+"1";
	    count=1;
	 }
	}

}

if(str.length()>=l)
System.out.println("NO");
else
System.out.println("YES");
	    T--;
	}
	}
}
