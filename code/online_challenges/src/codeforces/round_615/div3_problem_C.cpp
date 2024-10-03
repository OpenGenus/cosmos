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
	ll m=n;
	int counter = 0;
	ll arr[3] = {};
	ld var = sqrt(n);
	str ans = "";
	for(ll i=2; i<var;i++)
	{
		if(n%i == 0)
		{
			n/=i;
			arr[counter] = i;
			counter++;
			if(arr[counter-1]>=n)
			{
				ans = "NO\n";
				break;
			}
			if(counter == 2 && arr[0]*arr[1]*n == m)
			{
				arr[2] = n;
				break;
			}
		}		
	}	
	if(arr[2] == 0)
	{
		cout << "NO";
		return;
	}
	else
	{
		cout << "YES\n"
			 << arr[0] << ' ' << arr[1] << ' ' << arr[2];
	}
}

int main()
{	
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	*/
    fast;
    ll t=1;
    cin >> t;
    while(t--)
    {
    	solve();
    	if(t)
    		cout << '\n';
   	}
    return 0;
}
