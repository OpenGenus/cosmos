public class Problem003 {

	public static long smallestFactor(long n) {
		if (n <= 1)
			throw new IllegalArgumentException();
		for (long i = 2 ,end = (long)Math.sqrt(n); i <= end; i++) {
			if (n % i == 0)
				return i;
		}
		return n;
	}
	public static void main(String []args) {
		long n = 600851475143L;
		long big = 1;
		while(big != n) {
			big = smallestFactor(n);
			if (big < n)
				n /= big;
			else
				System.out.println(big);
		}
	}
}
