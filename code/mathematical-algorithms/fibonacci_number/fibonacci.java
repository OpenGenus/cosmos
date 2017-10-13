// Part of Cosmos by OpenGenus Foundation
public class fibonacci {

	public static long fibonacciTerm(int term){
		return calculateFibonacci(term - 2, 1, 1);
	}
	
	public static long calculateFibonacci(int a, int b, int c){
		if(a <= 0){
			return c;
		}
		return calculateFibonacci(a - 1, c, c + b);
	}
	
}
