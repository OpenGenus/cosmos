// Part of Cosmos by OpenGenus Foundation
class LongestCommonSubsequence {
    /* Returns length of longestCommonSubsequence for X[0..m-1], Y[0..n-1] */
  public int longestCommonSubsequence(String text1, String text2) {
        int dp[][] = new int[text1.length() + 1][text2.length() + 1];
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                if (text1.charAt(i) == text2.charAt(j))
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[text1.length()][text2.length()];
    }

  public static void main(String[] args) {
        LongestCommonSubsequence lcs = new LongestCommonSubsequence();
        String s1 = "AGGAGTCTAGCTAB";
        String s2 = "AGXGTTXAYBATCGAT";

        char []X = s1.toCharArray();
        char []Y = s2.toCharArray();
        int m = X.length;
        int n = Y.length;

        System.out.println("Length of LCS is" + " " + lcs.longestCommonSubsequence(X, Y, m, n));
    }
}
