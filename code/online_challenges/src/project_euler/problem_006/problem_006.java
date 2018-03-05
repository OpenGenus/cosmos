import java.util.*;
import java.lang.*;
import java.io.*;

class Problem006{
	public static void main(String[] args) {
		int sum = 0;
		int sqsum = 0;
		for (int i = 1; i <= 100; i++) {
			sqsum += i * i;
			sum += i;
		}
		System.out.println(sum * sum - sqsum);
	}
}
