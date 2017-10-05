// Part of Cosmos by OpenGenus Foundation 

/* 
**
** @AUTHOR: VINAY BADHAN
** @GREEDY PROBLEM: BABYLONIAN METHOD
** @GITHUB LINK: https://github.com/vinayb21
*/

import java.util.*;
import java.io.*;

class BabylonianMethod {
    
    public static double squareRoot(double num)
    {
        double error = 0.0000001;
        double x = num;
     
        while ((x - num / x) > error) {
     
            x = (x + num / x) / 2;
        }
        
        return x;
    }
    

    public static void main(String[] args) throws IOException {
        double n;
    	InputStreamReader in = new InputStreamReader(System.in);
    	BufferedReader buffer = new BufferedReader(in);
    	PrintWriter out = new PrintWriter(System.out, true);
    	out.println("Enter a non-negative number:");
    	String line = buffer.readLine().trim();
    	n = Double.parseDouble(line);
    	double ans = squareRoot(n);
    	out.println("Squareroot of "+n+" is "+ans);
    }
}
