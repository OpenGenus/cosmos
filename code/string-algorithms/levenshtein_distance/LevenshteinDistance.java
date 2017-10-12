// Part of Cosmos by OpenGenus Foundation
class LevenshteinDistance {
    private String a, b;
    private int n, m;
    private int[][] dp;

    public LevenshteinDistance(String a, String b) {
        this.a = a;
        this.b = b;
        n = a.length();
        m = b.length();

        dp = new int[n + 1][m + 1];

        initialize();
    }

    private void initialize() {
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
    }

    private int min3(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }

    public int compute() {

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                int c = (a.charAt(i - 1) == b.charAt(j - 1)) ? 0 : 1;

                dp[i][j] = min3(dp[i - 1][j - 1] + c, dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
        return dp[n][m];
    }

	public static void main(String[] args) {
	    LevenshteinDistance distance = new LevenshteinDistance("ana", "banana");
        System.out.println(distance.compute());
    }

}
