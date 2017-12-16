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
    
    /**
    * Counts the number of set bits in parallel.
    * @param n 32-bit integer whose set bits are to be counted
    * @return the number of set bits in (n)
    * @see <a href="https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel">Bit Twiddling Hacks</a>
    */
    public static int countSetBitsParallel(int n)
    {
        final int[] S = {
            1,
            2,
            4,
            8,
            16
        };

        final int[] B = {
            0x55555555,
            0x33333333,
            0x0F0F0F0F,
            0x00FF00FF,
            0x0000FFFF
        };

        int C = n - ((n >>> 1) & B[0]);
        C = ((C >>> S[1]) & B[1]) + (C & B[1]);
        C = ((C >>> S[2]) + C) & B[2];
        C = ((C >>> S[3]) + C) & B[3];
        C = ((C >>> S[4]) + C) & B[4];
        return C;
    }
    

    public static void main(String[] args) throws IOException {
        int n;
    	InputStreamReader in = new InputStreamReader(System.in);
    	BufferedReader buffer = new BufferedReader(in);
    	PrintWriter out = new PrintWriter(System.out, true);
    	String line = buffer.readLine().trim();
    	n = Integer.parseInt(line);
    	int ans = countSetBitsParallel(n);
    	out.println("No. of set bits in "+n+" is "+ans);
    }
}
