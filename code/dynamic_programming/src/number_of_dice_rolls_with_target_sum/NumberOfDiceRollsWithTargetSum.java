public class NumberOfDiceRollsWithTargetSum {

    public static void main(String[] args) {
        // Test case 1
        System.out.println(numRollsToTarget(1, 6, 3)); // it should output 1

        // Test case 2
        System.out.println(numRollsToTarget(30, 30, 500)); //it should output 222616187
        
    }

    public static int numRollsToTarget(int dices, int faces, int target) {
        /*
        * dp[i][j] = the number of possible ways modulo 10^9+7
        * i = the current i-th dice
        * j = the current number of points is j
         */
        long[][] dp = new long[35][1005];
        long MOD = (long)1e9 + 7;
        for (int i = 1; i <= faces; i++) dp[1][i] = 1; // Initialization assignment
        for (int i = 2; i <= dices; i++) {
            for (int j = i; j <= i * faces; j++) { // when j < i, it clearly does not exist.
                long count = 0;
                /*
                * Suppose the current dice i rolls the k-th face,
                * then it should be transferred from the point when the last dice was j-k
                * Note that J-K may be less than 1, so we have to limit the range of k
                 */
                for (int k = 1; k <= Math.min(faces, j - 1); k++) {
                    count = (count + dp[i - 1][j - k]) % MOD;
                }
                dp[i][j] = (dp[i][j] + count) % MOD;
            }
        }
        return (int)dp[dices][target];
    }
    
}
