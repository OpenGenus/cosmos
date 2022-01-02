public class LPS {
    static int longestPalindromicSubsequence(String s){
        int n = s.length();
        int[][] dp = new int[n][n];
        for(int l = 0; l < n; l++){
            for(int x = 0, y = x+l; x < n && y < n; x++,y++){
                if(l == 0){
                    dp[x][y] = 1;
                }else if(l == 1){
                    dp[x][y] = s.charAt(x) == s.charAt(y) ? 2 : 1;
                }else{
                    dp[x][y] = s.charAt(x) == s.charAt(y) ? 2 + dp[x+1][y-1] : Math.max(dp[x][y-1], dp[x+1][y]);
                }
            }
        }
        
        return dp[0][n-1];
    }
}
