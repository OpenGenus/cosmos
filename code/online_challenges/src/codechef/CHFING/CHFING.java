import java.io.*;
import java.util.*;
//reference from https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
class Graph
{
    static long power(long x, long y, long p) 
    { 
        long res = 1;      
        x = x % p;  
        while (y > 0) 
        { 
            if((y & 1)==1) 
                res = (res * x) % p; 
            y = y >> 1;  
            x = (x * x) % p;  
        } 
        return res; 
    } 
      static long modInverse(long a, long m) 
    { 
        return  power(a, m - 2, m); 
    }
     public static void main(String[] args)
    {
	   Scanner  s=new Scanner(System.in);
	   int t=s.nextInt();
	    long m=1000000007L;
	   for(int f=0;f<t;f++)
	   {
	       long n=s.nextLong();long k=s.nextLong();long p=0;
	       
	       
	            p=(k+n-2)/(n-1);
	            
	            long j=modInverse(2,m);
	              if((k+n-2)%(n-1)==0)
	            {
	                p--;
	                p=p%m;
	            long count=(-p*(n-1)+2*k+n-3+m)%m;
	            
	            count=((count*p)%m*j)%m;
	             System.out.println(count);
	             continue;
	            }
	             
	            p=p%m;
	            
	            
	            long count=(-p*(n-1)+2*k+n-3+m)%m;
	           
	            count=((count*p)%m*j)%m;
	            
	            
	            System.out.println(count);
	   }
					
					

	   	}
 
}