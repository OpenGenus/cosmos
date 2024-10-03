#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define str string
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define MAX 1000000
#define mod 1000000007

void solve()
{
	ll a,b,c,n, min=0;
	cin >> a >> b >> c >> n;
	str ans;
	int odd = 0, even = 0;
	ll max=0;
	if(a > b && a > c)
	{
		max = a;
	}
	else if(b > c)
	{
		max = b;
	}
	else
	{
		max = c;
	}
	min = 3* max - (a + b + c);
	if(min > n)
		cout << "NO\n";
	else if((n-min)%3 != 0)
		cout << "NO\n";
	else 
		cout <<"YES\n";
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
