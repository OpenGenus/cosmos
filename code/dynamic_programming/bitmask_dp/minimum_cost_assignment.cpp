#include <iostream>

#define ll long long
#define db(x) cout << "> " << #x << " : " << x << endl;

const int N = 12;
const int INF = (1 << 30);
using namespace std;

inline int bit(int mask, int idx) { return ((mask & (1 << idx)) != 0); }

int n;
int cost[N][N];

int dp[(1 << N) +100];
bool vis[(1 << N) +100];

int f(int mask)
{
	if(mask == ((1 << n) -1))
		return 0;
	
	if(vis[mask])
		return dp[mask];
	
	int res = INF;
	int curr = __builtin_popcount(mask);
	
	for(int job = 0; job < n; job++)
		if(!bit(mask, job))
			res = min(res, cost[curr][job] +f(mask | (1 << job)));	
	
	vis[mask] = 1;
	dp[mask] = res;
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> cost[i][j];	// cost for ith person to do jth job
	
	// assign each person a job such that total cost is minimized and no job is repeated
			
	cout << f(0) << '\n';
	return 0;
}
