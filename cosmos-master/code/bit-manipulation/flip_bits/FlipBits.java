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
        int flipN = 0;
        int pow = 0;

        while(n>0)
        {
            if(n%2==0)
                flipN += (1 << pow);
            n/=2;
            pow++;
        }
        return flipN;
    }

    public static void main(String[] args) throws IOException {
    	InputStreamReader in = new InputStreamReader(System.in);
    	BufferedReader buffer = new BufferedReader(in);
    	String line = buffer.readLine().trim();
    	int n = Integer.parseInt(line);
    	int ans = flipBits(n);
    	System.out.println("Number obtained by flipping bits of "+n +" is "+ans);
    }
}
