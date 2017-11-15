// dynamic programming | binomial coefficient | Java
// Part of Cosmos by OpenGenus Foundation

import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class BinomialCoefficient{
	static int binomialCoeff(int n, int k) {
		if (k>n) {
			return 0;
		}
		
		int c[] = new int[k+1];
		int i, j;
		
		c[0] = 1;
		
		for (i=0; i<=n; i++) {
			for (j=min(i,k); j>0; j--) {
				c[j] = c[j] + c[j-1];
			}
		}
		
		return c[k];
	}
	
	static int min(int a, int b) {
		return (a<b)? a: b;
	}
	
	//test case
	public static void main(String args[]) {
		int n = 5, k = 2;
		System.out.println("Value of C("+n+","+k+") is "+binomialCoeff(n, k));
	}
}
