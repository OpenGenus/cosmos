/* Part of Cosmos by OpenGenus Foundation */

public class EulerTotient {

	public static int phi(int n) {

		if (n <= 0)
			return 0;

		int res = n;

		for (int i = 2; i * i <= n; i++){
			if (n % i == 0){
				do {
					n /= i;
				} while (n % i == 0);
				res -= res / i;
			}
		}

		if (n != 1) {
			res = res * (n-1) / n;
		}
		return res;
	}


	public static void main(String[] args) {
		int[] testCases = {
			1,       // denegerate case
			2,       // prime
			11,      // prime
			2*2,     // power of prime
			3*3*3,   // power of prime
			3*5,     // product of distinct primes
			2*2*3*3, // product of distinct primes
			5*23,    // product of distinct primes
			5*5*23,  // product of distinct primes
		};
		int[] expectedResults = {
			1,
			1,
			10,
			2,
			18,
			8,
			12,
			88,
			440,
		};

		for (int idx = 0; idx < testCases.length; idx++) {
			System.out.println("phi(" + testCases[idx] + ") = " + phi(testCases[idx]));
			System.out.println("Expected: " + expectedResults[idx]);
		}
	}
}

