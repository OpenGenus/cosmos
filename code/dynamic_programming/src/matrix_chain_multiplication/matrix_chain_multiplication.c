/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>
#define inf_ll 2000000000000000000LL
#define inf 1000000000
#define eps 1e-8
#define mod 1000000007
#define ff first
#define ss second
#define N 3456789
typedef long long int ll;
ll dp[987][987];
ll ar[N];

/*
Matrix Chain Multiplication Problem

You are given N matrices A_1, A_2, A_3 .... A_N. You need to find product (A_1 * A_2 * A_3 .... A_N) 
As matrix product is associative, there can be different ways of computing the same product. 
For example (A*B*C*D) can be computed as (((A*B)*C)*D) or ((A*B)*(C*D)). 
The cost of multiplying two matrices X and Y is given by the number of integer multiplications which 
we need to perform while multiplying them. Among all possible ways of multiplying the given matrices 
and arriving at the same product, print the minimum total integer multiplications which
we need to perform.

Input Format - 
The first line contains number of matrices N
The second line contains N+1 integers B_0, B_1, B_2 ..... B_N.
The dimensions of matrix A_i is given by B_(i-1)*B_i. for every i between 1 and N

Output Format - 
Print on a single line the answer to the above problem

Constraints - 
1 <= N <= 500
1 <= B_i <= 10000 for every i between 0 and N

Example - 

Input - 
4
5 5 5 5 1

Output -
75

Explanation - 
Minimum cost is achieved by multiplying matrices in the following order
(A_1*(A_2*(A_3*A_4))). In this order, the cost of each matrix multiplication is 25.
*/

ll min (ll x, ll y) {
	return x < y ? x : y;
}

int main () {
	ll n, len, i, j, k;
	scanf("%lld", &n);
	n += 1;
	for (i = 0; i < n; i++) scanf("%lld", &ar[i]);
	for (len = 2; len < n; len++) {			// Loop on the length of the subproblem
		for (i = 1; i < n - len + 1; i++) {		// Loop on the starting index of subproblem
			j = i + len - 1;
			dp[i][j] = inf_ll;
			for (k = i; k < j; k++) {		// Finding the optimal solution for dp[i][j]
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + ar[i-1] * ar[k] * ar[j]);
			}
		}
	}
	printf("%lld\n", dp[1][n-1]);
	return 0;
}