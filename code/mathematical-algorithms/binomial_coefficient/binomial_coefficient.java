public class BinomialCoefficient {
// Part of Cosmos by OpenGenus Foundation
	public long solve(int n, int k) {
		long bc[][] = new long[n+1][n+1];

		for(int i = 0; i <= n; i++) {
			bc[i][0] = 1;
		}

		for(int j = 0; j <= n; j++) {
			bc[j][j] = 1;
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
			}
		}

		return bc[n][k];
	}

	public static void main(String[] args) {
		BinomialCoefficient solver = new BinomialCoefficient();
		System.out.println(solver.solve(10,5));
	}
}
