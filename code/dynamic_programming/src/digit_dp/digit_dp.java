/* Part of Cosmos by OpenGenus Foundation */

/* How many numbers x are there in the range a to b?
 * where the digit d occurs exactly k times in x?
 */

import java.util.Arrays;

public class DigitDP {
    private static int d = 3;
    private static int k = 5;
    private static int[][][] dp = new int[25][25][2];
    /* dp[pos][count][f] = Number of valid numbers <= b from this state
    * pos = current position from left side (zero based)
    * count = number of times we have placed the digit d so far
    * f = the number we are building has already become smaller than b? [0 = no, 1 = yes]
    */

    public static void main(String args[]) {
        String a = "100";
        String b = "100000000";
        int ans = solve(b) - solve(a) + check(a);
        System.out.println(ans);
    }

    private static int check(String num) {
        int count = 0;
        for(int i = 0; i < num.length(); ++i)
            if (num.charAt(i) - '0' == d)
                count++;

        if (count == k)
            return 1;
        return 0;
    }

    private static int solve(String num) {
        for(int[][] rows: dp)
            for(int[] cols: rows)
                Arrays.fill(cols, -1);
        int ret = digit_dp(num, 0, 0, 0);
        return ret;
    }

    private static int digit_dp(String num, int pos, int count, int f) {
        if (count > k)
            return 0;
        if (pos == num.length()) {
            if (count == k)
                return 1;
            return 0;
        }
        if (dp[pos][count][f] != -1)
            return dp[pos][count][f];
        int res = 0;
        int limit;
        if (f == 0) {
            /* Digits we placed so far matches with the prefix of b
            * So if we place any digit > num[pos] in the current position, then
            * the number will become greater than b
            */
            limit = num.charAt(pos) - '0';
        } else {
            /* The number has already become smaller than b.
            * We can place any digit now.
            */  
            limit = 9;
        }

        // Try to place all the valid digits such that the number does not exceed b
        for(int dgt = 0; dgt <= limit; ++dgt) {
            int fNext = f;
            int countNext = count;

            // The number is getting smaller at this position
            if (f == 0 && dgt < limit)
                fNext = 1;
            if (dgt == d)
                countNext++;
            if (countNext <= k)
                res += digit_dp(num, pos + 1, countNext, fNext);
        }
        dp[pos][count][f] = res;
        return dp[pos][count][f];
    }
}

