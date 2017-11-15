/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cstring>

#define MAX 110
#define MAX_SUM 100100

int reachable[MAX_SUM];
bool dp[MAX_SUM];

using namespace std;

/*  
 *  Check whether is possible to
 *  get value sum from a subset 
 *  of the array v
 */
bool canGetSum(int v[], int n, int sum) {
    
    memset(dp, 0, sizeof dp);
    reachable[0] = 0;
    dp[0] = true;
    for(int i = 0, q = 1; i < n && !dp[sum]; ++i) {
        int aux = q;
        for(int j = 0; j < aux; ++j) {
            int x = reachable[j] + v[i];
            if(x <= sum && !dp[x]) {
                reachable[q++] = x;
                dp[x] = true;
            }
        }
    }
    return dp[sum];
}

int main()
{
    int v[] = { 1, 2, 15, 8, 5};

    cout << (canGetSum(v, sizeof(v) / sizeof(v[0]), 13) ? "possible" : "impossible") << "\n";
    cout << (canGetSum(v, sizeof(v) / sizeof(v[0]),  4) ? "possible" : "impossible") << "\n";
	return 0;
}
