// Part of Cosmos by OpenGenus Foundation 

/* 
**
** @AUTHOR: VINAY BADHAN
** @BIT MANIPULATION PROBLEM: Nth MAGIC NUMBER
** @GITHUB LINK: https://github.com/vinayb21
*/

import java.util.*;
import java.io.*;

class MagicNumber {
    
    public static int magicNumber(int n)
    {
        int pow = 1, ans = 0;
        while(n > 0)
        {
            pow = pow*5;
    
            if (n%2==1)
                ans += pow;
            n >>= 1;  
        }
        return ans;
    }
    

    public static void main(String[] args) throws IOException {
        int n;
    	InputStreamReader in = new InputStreamReader(System.in);
    	BufferedReader buffer = new BufferedReader(in);
    	PrintWriter out = new PrintWriter(System.out, true);
    	String line = buffer.readLine().trim();
    	n = Integer.parseInt(line);
    	int ans = magicNumber(n);
    	out.println(n+"th Magic Number is "+ans);
    }
}
