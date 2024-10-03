// Part of Cosmos by OpenGenus Foundation 

import java.io.*;
import java.util.*;
import java.lang.*;

public class Coprime{
	public static void main(String[] args) throws IOException{
		int id1, id2, cases, divisor;
	
// Reads in the number of cases
		cases = 5;
		
// Goes through each case one by one
		for(int index = 1;index < cases;index++){

// Reads in the 2 numbers			
			id1 = index*3;
			id2 = index*5;
			
// Goes through each potential factor and checks if any number divides into both.
			for(divisor = 2;divisor <= Math.min(id1, id2) && (id1%divisor != 0 || id2%divisor != 0);divisor++);
			
// If the divisor is greater than the min between the two, it did not find a factor between the two
			if(divisor > Math.min(id1, id2))
				System.out.println(id1 + " and " + id2 + ", are coprime");
// Otherwise, the two numbers are not coprime				
			else
				System.out.println(id1 + " and " + id2 + ", are not coprime");
		}
	}
}
