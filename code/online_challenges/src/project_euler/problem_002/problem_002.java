/*

// online challenges | project euler | problem 002 | problem 002 | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


public class Problem002 {
	public static void main(String[] args) {
		int sum = 0;
		int first = 0;
		int second = 1;
		int third = 0;
		while(third < 4000000) {
			third = first + second;
			sum += (third % 2 == 0) ? third : 0;
			first = second;
			second = third;
		}
		System.out.println(sum);
	}
}
