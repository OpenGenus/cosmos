#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define str string
#define pb push_back
#define fr(i,n) for(ll i=0; i<n; i++)
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define MAX 1000000
#define mod 1000000007

void solve()
{
	ll n;
	cin >> n;
	int x,y;
	str ans = "";
	ll max = 0;
	vector<vector<int> > arr(1001);
	fr(i,n)
	{
		cin >> x >> y;
		if(max < x)
			max = x;
		arr[x].pb(y);
	}
	fr(i, max+1)
	{
		sort(all(arr[i]));
	}
	ll counter = 0;
	for(ll i=0; i<max+1; i++)
	{
		fr(j, arr[i].size())
		{
			if(arr[i][j] < counter)
			{
				ans = "NO";
				break;
			}
			for(;counter<arr[i][j];counter++)
			{
				ans+="U";
			}
		}
		if(ans == "NO")
		{
			break;
		}
		ans+="R";		
	}
	if(ans == "NO")
	{
		cout << "NO\n";
		return;
	}
	else
	{
		str ans2= "";
		for(ll i=0; i<ans.size()-1; i++)
		{
			ans2+=ans[i];
		}
		cout << "YES\n" <<ans2 << '\n';
	}

}

int main()
{
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//#endif
    fast;
    ll t=1;
    cin >> t;
    while(t--)
    	solve();
    return 0;
}
