//  divide conquer | karatsuba multiplication | Java
//  Part of Cosmos by OpenGenus Foundation

import java.lang.*;
import java.util.Scanner;

public class Multiply
{
	public static String trim(String str,int n)
	{
		if(str.length()>n)
			while(str.charAt(0)=='0' && str.length()>n)
			str=str.substring(1);
		else
			while(str.length()!=n)
			str="0"+str;
		return str;
	}
	public static String add_str(String a,String b,int n)
	{
		a=trim(a,n);
		b=trim(b,n);
		String val="";
		int i,rem=0;
		char []c1=a.toCharArray();
		char []c2=b.toCharArray();
		int ans[]=new int[a.length()+1];
		for(i=a.length();i>0;i--)
		{
		ans[i]=(c1[i-1]-48+c2[i-1]-48+rem)%10;
		rem=(c1[i-1]-48+c2[i-1]-48+rem)/10;
		}
		ans[0]=rem;
		for(i=0;i<ans.length;i++)
		val=val+ans[i];
		val=trim(val,a.length()+1);
		return val;
	}

	public static String multiply(String s1,String s2,int n)
	{
		String a,b,c,d,ac,bd,ad_bc,ad,bc;
		int i;
		if(n==1)
			return Integer.toString(Integer.parseInt(s1)*Integer.parseInt(s2));
		a=s1.substring(0,n/2);
		b=s1.substring(n/2,n);
		c=s2.substring(0,n/2);
		d=s2.substring(n/2,n);
		ac=multiply(a,c,n/2);
		bd=multiply(b,d,n/2);
		ad=multiply(a,d,n/2);
		bc=multiply(b,c,n/2);
		ad_bc=add_str(ad,bc,n);

		for(i=1;i<=n;i++)
			ac=ac+"0";
		for(i=1;i<=n/2;i++)
			ad_bc=ad_bc+"0";
		ac=trim(ac,n*2);
		ad_bc=trim(ad_bc,n*2);
		bd=trim(bd,n*2);
		return add_str(add_str(ac,ad_bc,n*2),bd,n*2);
	}

	public static void main(String args[])
	{
		int n;
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter first number=");
		String s1=sc.next();
		System.out.print("Enter second number=");
		String s2=sc.next();
		n=s1.length();
		String s3=multiply(s1,s2,n);
		System.out.println(s3);
	}
}
