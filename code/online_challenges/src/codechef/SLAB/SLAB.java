import java.io.*;
import java.util.*;
class A
{
	public static void main(String[] args) throws IOException
	{
	    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

	    int i,N;

	    int T=Integer.parseInt(br.readLine().trim());
	    StringBuilder sb=new StringBuilder();

	    while(T-->0)
	    {
	        N=Integer.parseInt(br.readLine().trim());

	        int tax=0;
	        if(N>250_000)
	            tax+=(Math.min(N,500_000)-250_000)*5/100;
	        if(N>500_000)
	            tax+=(Math.min(N,750_000)-500_000)*10/100;
	        if(N>750_000)
	            tax+=(Math.min(N,1_000_000)-750_000)*15/100;
	        if(N>1_000_000)
	            tax+=(Math.min(N,1_250_000)-1_000_000)*20/100;
	        if(N>1_250_000)
	            tax+=(Math.min(N,1_500_000)-1_250_000)*25/100;
	        if(N>1_500_000)
	            tax+=(N-1_500_000)*30/100;

	        int net=N-tax;
	        sb.append(net).append("\n");
	    }
	    System.out.println(sb);
	}
}