import java.util.*;
import java.math.*;
class GFG {
	public static void main (String[] args) {

		Scanner sc=new Scanner(System.in);
	    int t=sc.nextInt();
		while(t-->0)
		{
			BigInteger pw=new BigInteger("2");
			BigInteger q=new BigInteger("1000000007");
		    long n=sc.nextLong();
		    long k=sc.nextLong();
		    long res=(k-1);
		    long ans=2*(k-n);
		    if(ans<0)
		    {
				System.out.println(res%1000000007);
			}
			else
			{
				long st=k-n;
				long cd=n-1;
				long term=(k-n)/(n-1);
				long p=(term+1);
				BigInteger a=new BigInteger(""+ans);
				BigInteger b=new BigInteger(""+res);
				BigInteger x=new BigInteger(""+term);
				BigInteger c=new BigInteger(""+st);
				BigInteger z=new BigInteger((""+cd));
				BigInteger m=new BigInteger((""+p));
				z=z.multiply(x);
				a=a.subtract(z);
				m=(m.multiply(a)).divide(pw);
				m=m.add(b);
				m=m.mod(q);
				System.out.println(m);
		    }
		}
	}
}