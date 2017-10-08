// Part of Cosmos by OpenGenus Foundation 

/* 
**
** @AUTHOR: VINAY BADHAN
** @BIT MANIPULATION PROBLEM: FLIP BITS
** @GITHUB LINK: https://github.com/vinayb21
*/

import java.util.*;
import java.io.*;

class FlipBits {
    
    public static int flipBits(int n)
    {
        int flipN, pow;
        flipN = 0;
        pow = 0;
        while(n>0)
        {
            if(n%2==0)
                flipN += (int)Math.pow(2,pow);
            n = n/2;
            pow++;
        }
        return flipN;
    }
    

    public static void main(String[] args) throws IOException {
        int n;
    	InputStreamReader in = new InputStreamReader(System.in);
    	BufferedReader buffer = new BufferedReader(in);
    	PrintWriter out = new PrintWriter(System.out, true);
    	String line = buffer.readLine().trim();
    	n = Integer.parseInt(line);
    	int ans = flipBits(n);
    	out.println("Number obtained by flipping bits of "+n+" is "+ans);
    }
}
