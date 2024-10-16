class DPprob {
    public int minSkips(int[] A, int s, int target) {
        int n = A.length, dp[] = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = n; j >= 0; --j) {
                dp[j] += A[i];
                if (i < n - 1)
                    dp[j] = (dp[j] + s - 1) / s * s; // take a rest
                if (j > 0)
                    dp[j] = Math.min(dp[j], dp[j - 1] + A[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (dp[i] <= (long) s * target)
                return i;
        }
        return -1;
    }

    public static void main(String args[]) {
/*Example 1:

Input: dist = [1,3,2], speed = 4, hoursBefore = 2
Output: 1
Explanation:
Without skipping any rests, you will arrive in (1/4 + 3/4) + (3/4 + 1/4) + (2/4) = 2.5 hours.
You can skip the first rest to arrive in ((1/4 + 0) + (3/4 + 0)) + (2/4) = 1.5 hours.
Note that the second rest is shortened because you finish traveling the second road at an integer hour due to skipping the first rest.*/
        int dist1 = {1, 3, 2};
        int speed1 = 4;
        int hoursBefore1 = 2;
        System.out.println(minSkips(dist1, speed1, hoursBefore1));
    }
}