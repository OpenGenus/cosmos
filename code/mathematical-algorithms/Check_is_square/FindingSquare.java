// Part of Cosmos by OpenGenus Foundation 

import java.io.*;
import java.util.*;

public class CheckisSquare{	

	static boolean checkIsSquare(int n){
		boolean flag = false;
		int start = 0;
		int end = n;
		while(start <= end){
			int mid = start + (end - start) / 2;
			long val = (long)mid * (long)mid;
			if(val == n)
				return true;
			else if(val < n)
				start = mid + 1;
			else
				end = mid - 1;
		}

		return false;
	}

	public static void main(String[] args) throws IOException{
		try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){		
			
			int n = 0;
			do{
				System.out.println("Please Enter a Positive Integer :");
				n = Integer.parseInt(br.readLine().trim());
			}while(n < 0);

			if(checkIsSquare(n))
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}	
}
