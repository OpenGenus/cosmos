/*
	Input: 
		
	3
	1 2 3
	3 2 1
	2 1 3
	
	Output: 3
*/

#include <iostream>

const int N = 12;
const int INF = (1 << 30);

using namespace std;

inline int bit(int mask, int idx) { return ((mask & (1 << idx)) != 0); }	// returns the idx-bit in mask

int n;
int cost[N][N];

int dp[(1 << N) +100];
bool vis[(1 << N) +100];

int f(int mask)
{
	if(mask == ((1 << n) -1))	// if all jobs are assigned we are done
		return 0;
	
	if(vis[mask])	// making sure that answer for each state is calculated only once
		return dp[mask];
	
	int res = INF;
	int curr = __builtin_popcount(mask);
	
	// number of set  bits in the mask gives the number of persons to whom a job was assigned
	
	for(int job = 0; job < n; job++)
		if(!bit(mask, job))
			res = min(res, cost[curr][job] +f(mask | (1 << job)));	
	
	vis[mask] = 1;
	dp[mask] = res;
	return res;
}

int main()
{
	//fast-io
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << "\nEnter number of people:" << endl;
	cin >> n;
	
	cout << "\nEnter the cost-matrix (consisting of n rows and n columns where the element in ith row and jth column represents cost for ith person to do jth job) :" << endl;
	 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> cost[i][j];	// cost for ith person to do jth job
	
	// assign each person a job such that total cost is minimized and no job is repeated
			
	cout << f(0) << '\n';
	return 0;
}
