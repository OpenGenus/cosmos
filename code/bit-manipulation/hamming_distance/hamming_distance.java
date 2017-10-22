// Part of Cosmos by OpenGenus Foundation

// The Hamming distance between two integers is the number of positions 
// at which the corresponding bits are different.

import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class HammingDistance {
	private int hammingDistance(int x, int y) {
		int temp = x^y;
		int count = 0;
		
		//count the number of set bits in the xor of two numbers
		while(temp != 0){
			temp = temp&(temp-1);
			count++;
		}
		return count;
	}
	
	public static void main(String args[]) {
		HammingDistance ob = new HammingDistance();
		int testHammingDistance = ob.hammingDistance(2,5);
		System.out.println(testHammingDistance);
	}
}