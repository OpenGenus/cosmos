/* Part of Cosmos by OpenGenus Foundation
 * By: Sibasish Ghosh (https://github.com/sibasish14)
 */

/* How many numbers x are there in the range a to b?
 * where the digit d occurs exactly k times in x?
 */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

long d = 3;
long k = 5;

long dp[25][25][2];
/* dp[pos][count][f] = Number of valid numbers <= b from this state
 * pos = current position from left side (zero based)
 * count = number of times we have placed the digit d so far
 * f = the number we are building has already become smaller than b? [0 = no, 1 = yes]
 */

long digit_dp(string num, long pos, long count, long f)
{
    if (count > k)
        return 0;

    if (pos == num.size())
    {
        if (count == k)
            return 1;
        return 0;
    }

    if (dp[pos][count][f] != -1)
        return dp[pos][count][f];

    long result = 0;
    long limit;

    if (f == 0)
        /* Digits we placed so far matches with the prefix of b
         * So if we place any digit > num[pos] in the current position, then
         * the number will become greater than b
         */
        limit = num[pos] - '0';
    else
        /* The number has already become smaller than b.
         * We can place any digit now.
         */
        limit = 9;

    // Try to place all the valid digits such that the number doesn't exceed b
    for (long dgt = 0; dgt <= limit; dgt++)
    {
        long fNext = f;
        long countNext = count;

        // The number is getting smaller at this position
        if (f == 0 && dgt < limit)
            fNext = 1;

        if (dgt == d)
            countNext++;

        if (countNext <= k)
            result += digit_dp(num, pos + 1, countNext, fNext);
    }

    return dp[pos][count][f] = result;
}

long solve(string num)
{
    memset(dp, -1, sizeof(dp));
    long result = digit_dp(num, 0, 0, 0);
    return result;
}

bool check(string num)
{
    long count = 0;
    for (long i = 0; i < num.size(); i++)
        if (num[i] - '0' == d)
            count++;

    if (count == k)
        return true;
    else
        return false;
}

int main()
{
    string a = "100", b = "100000000";
    long ans = solve(b) - solve(a) + check(a);
    cout << ans << "\n";
    return 0;
}
