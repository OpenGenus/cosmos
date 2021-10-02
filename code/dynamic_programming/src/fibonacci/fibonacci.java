//Top Down Approach!
class Solution {

    public int fib(int n) {
        if (n < 2)
            return n;
        int[] dp = new int[n + 1];
        return fibHelp(n, dp);
    }

    static int fibHelp(int n, int[] dp) {
        if (n < 2)
            return n;
        if (dp[n] != 0)
            return dp[n];
        return dp[n] = fibHelp(n - 1, dp) + fibHelp(n - 2, dp);
    }
}

// Bottom Up Approach!
class Solution {

    public int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int dp[] = new int[n + 1];
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}

// Another one
class Solution {

    public int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int i = 0, j = 1, num = 0;
        while (n-- > 1) {
            num = i + j;
            i = j;
            j = num;
        }
        return num;
    }
}