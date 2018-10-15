/* Part os Cosmos by OpenGenus Foundation */

#include <iostream>

#define MAX_EGGS 100
#define MAX_FLOORS 100
#define INF 1000000000

using namespace std;

int memo[MAX_EGGS][MAX_FLOORS];

/*
 *  Returns the minimum number of attempts
 *  needed in the worst case for n eggs
 *  and k floors.
 *  Time complexity: O(n*k^2)
 */
int eggDrop(int n, int k)
{

    // base cases
    if (k == 0)
        return 0;        // if there is no floor, no attempt is necessary
    if (k == 1)
        return 1;        // if there is only one floor, just one attempt is necessary
    if (n == 1)
        return k;        // with only one egg, k attempts are necessary

    // check if it is already computed
    if (memo[n][k] > -1)
        return memo[n][k];

    int ans = INF;
    // attempt to drop an egg at each height from 1 to k
    for (int h = 1; h <= k; ++h)
        ans = min(ans, max(    // get worst case from:
                      eggDrop(n - 1, h - 1), // case in which egg breaks
                      eggDrop(n, k - h) // case in which egg does not break
                      ));

    return memo[n][k] = ans + 1; // store minimum value
}

int main()
{
    for (int i = 0; i < MAX_EGGS; ++i)
        for (int j = 0; j < MAX_FLOORS; ++j)
            memo[i][j] = -1;

    cout << eggDrop(2, 100) << '\n';
    cout << eggDrop(10, 5) << '\n';
    cout << eggDrop(10, 100) << '\n';
    return 0;
}
