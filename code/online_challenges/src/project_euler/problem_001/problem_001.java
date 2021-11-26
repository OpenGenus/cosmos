/*

// online challenges | project euler | problem 001 | problem 001 | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


public class Problem001 {
	public static void main(String []args) {
		int sum = 0;
		for(int i = 1; i < 1000; i++) 
			sum += (i % 3 ==0 || i % 5 == 0) ? i : 0;
		System.out.print(sum);
	} 
}
