#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
#define ll long long
// #define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
const int mod=1000000007;
// const int INF=1e18;
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,tax=0;
		cin>>n;
		if(n>250000)
			tax += ( (min(500000,n)-250000)*5 )/100;
		if(n>500000)
			tax += ( (min(750000,n)-500000)*10 )/100;
		if(n>750000)
			tax += ( (min(1000000,n)-750000)*15 )/100;
		if(n>1000000)
			tax += ( (min(1250000,n)-1000000)*20 )/100;
		if(n>1250000)
			tax += ( (min(1500000,n)-1250000)*25 )/100;
		if(n>1500000)
			tax += ( (n-1500000)*30 )/100;
		cout<<n-tax<<'\n';
	}
	
	return 0;
} 