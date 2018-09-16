public class SteinerTree {

	public static int minLengthSteinerTree(int[][] g, int[] verticesToConnect) {
		int n = g.length;
		int m = verticesToConnect.length;
		if (m <= 1)
			return 0;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);

		int[][] dp = new int[1 << m][n];

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				dp[1 << i][j] = g[verticesToConnect[i]][j];

		for (int i = 1; i < 1 << m; i++) {
			if (((i - 1) & i) != 0) {
				for (int j = 0; j < n; j++) {
					dp[i][j] = Integer.MAX_VALUE / 2;
					for (int k = (i - 1) & i; k > 0; k = (k - 1) & i) {
						dp[i][j] = Math.min(dp[i][j], dp[k][j] + dp[i ^ k][j]);
					}
				}
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						dp[i][j] = Math.min(dp[i][j], dp[i][k] + g[k][j]);
					}
				}
			}
		}

		return dp[(1 << m) - 1][verticesToConnect[0]];
	}
}
