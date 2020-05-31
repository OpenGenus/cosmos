/*
 *
 * Part of Cosmos by OpenGenus Foundation
 *
 * Description:
 *  1. We start with i = 0...N number of considered obejcts, where N is the
 *     total number of objects we have. Similarly, for the capacity of bag we
 *     go from b = 0...B where B is maximum capacity.
 *  2. Now for each pair of (i, b) we compute the subset of objects which will
 *     give us the maximum value, starting from i = 1 to N and b from 0 to B.
 *  3. We compute a "dp" where dp[i][b] will give us the maximum value when
 *     we consider the first i elements and the weight is b.
 *  4. We take a bottom-up approach, first filling dp[0][...] = 0 (we consider 0 elements)
 *     and dp[...][0] = 0 (as capacity of bag is 0, value will be 0).
 *  5. Now, for each (i, b) we either include the 'i'th object or we do not.
 *     dp[i][b] is the max of both these approaches. 
 *     Case 1: If we do not include the 'i'th object, our max value will be the same
 *             as that for first (i - 1) objects to be filled in capacity b.
 *             i.e. dp[i - 1][b]
 *     Case 2: If we do include the 'i'th object, we need to clear space for it. For this,
 *             we compute the best score when the first (i - 1) objects were made to fit in
 *             a bag of capacity (b - Wi) where Wi is the weight of ith object. We add the 
 *             value of ith object to this score. If Vi denotes the value of ith object, the
 *             best possible score after includig object i is:
 *             dp[i - 1][b - Wi] + Vi
 *  6. We get the formula: dp[i][b] = max(dp[i-1][b], dp[i-1][b-Wi] + Vi)
 *     As we have computed the base cases dp[0][...] and dp[...][0] we can use this formula
 *     for the rest of the table and our required value will be dp[N][B].
 *
 */
#include <utility>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MOD 1000000007
#define INF 1000000000
#define pb push_back
#define sz size()
#define mp make_pair

//cosmos: knapsack 0-1
int knapsack(int value[], int weight[], int n_items, int maximumWeight)
{
    // dp[N + 1][B + 1] to accommodate base cases i = 0 and b = 0
    int dp[n_items + 1][maximumWeight + 1];

    // Base case, as we consider 0 items, value will be 0
    for (int w = 0; w <= maximumWeight; w++)
        dp[0][w] = 0;

    // We consider weight 0, therefore no items can be included
    for (int i = 0; i <= n_items; i++)
        dp[i][0] = 0;

    // Using formula to calculate rest of the table by base cases
    for (int i = 1; i <= n_items; i++)
        for (int w = 1; w <= maximumWeight; w++)
        {
            // Only consider object if weight of object is less than allowed weight
            if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }

    return dp[n_items][maximumWeight];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int value[] = {12, 1000, 30, 10, 1000};
    int weight[] = {19, 120, 20, 1, 120};
    int n_items = 5;
    int maximumWeight = 40;

    cout << knapsack(value, weight, n_items, maximumWeight) << endl;    //values of the items, weights, number of items and the maximum weight
    return 0;
}
