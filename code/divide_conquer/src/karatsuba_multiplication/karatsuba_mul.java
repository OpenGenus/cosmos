import java.io.*;
//Karatsuba Multiplication 
//for generalized to any base
class GFG {
    
	public static void main (String[] args) {
		System.out.println(multiply(1100,1010,2));
		System.out.println(multiply(120,45,10));
	}
	
	private static long  multiply(long x,long y,int BASE){
	    int xLength = Long.toString(x).length();
	    int yLength = Long.toString(y).length();
	   
	    int max = Math.max(xLength,yLength);
	    
	    if(max < 10)
	        return (long)x*(long)y;
	    int N = max/2;
	    long multiplier = (long)Math.pow(BASE,N);
	    long a = x/multiplier;
	    long b = x%multiplier;
	    long c = y/multiplier;
	    long d = y%multiplier;
	    
	    long ac = multiply(a,c,BASE);
	    long bd = multiply(b,d,BASE);
	    long res = multiply((a+b),(c+d),BASE);
	    
	 long result = ac * (long)Math.pow(BASE,N)+ bd+((long)Math.pow(BASE,N/2)*res);
	 return result;
	}
}
