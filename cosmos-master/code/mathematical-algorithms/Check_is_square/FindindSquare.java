// Part of Cosmos by OpenGenus Foundation 

/* 
**
** @AUTHOR: VINAY BADHAN
** @GREEDY PROBLEM: FINDING SQUARE
** @GITHUB LINK: https://github.com/vinayb21
*/

import java.util.*;
import java.io.*;

class FindingSquare {
    
    public static boolean isSquare(int n)
    {
        int i,fact1,fact2;
        for(i=1;i<=n/2;i++)
        {
            if(n/i==i)
                return true;
        }
        return false;
    }
    

    public static void main(String[] args) throws IOException {
        int n;
    	InputStreamReader in = new InputStreamReader(System.in);
    	BufferedReader buffer = new BufferedReader(in);
    	PrintWriter out = new PrintWriter(System.out, true);
    	out.print("Enter a non-negative number: ");
    	out.println();
    	String line = buffer.readLine().trim();
    	n = Integer.parseInt(line);
    	boolean ans = isSquare(n);
        if(ans)
            out.println(n+" is a perfect square");
        else
            out.println(n+" is not a perfect square");
    }
}
