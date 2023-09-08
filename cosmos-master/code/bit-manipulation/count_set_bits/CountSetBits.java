// Part of Cosmos by OpenGenus Foundation 

/* 
**
** @AUTHOR: VINAY BADHAN
** @GREEDY PROBLEM: COUNT SET BITS
** @GITHUB LINK: https://github.com/vinayb21
*/

import java.util.*;
import java.io.*;

class CountSetBits {
    
    public static int countSetBits(int n)
    {
        int count = 0,bit;
        while(n>0)
        {
            bit = n&1;
            if(bit==1)
                count++;
            n >>= 1;
        }
        return count;
    }
    

    public static void main(String[] args) throws IOException {
        int n;
    	InputStreamReader in = new InputStreamReader(System.in);
    	BufferedReader buffer = new BufferedReader(in);
    	PrintWriter out = new PrintWriter(System.out, true);
    	String line = buffer.readLine().trim();
    	n = Integer.parseInt(line);
    	int ans = countSetBits(n);
    	out.println("No. of set bits in "+n+" is "+ans);
    }
}
