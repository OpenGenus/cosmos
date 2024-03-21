#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define MAX 1000000
#define mod 1000000007
void solve()
{
    ll n,i,a[MAX],b[MAX],min,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
      cin>>a[i];
    for(i=0;i<n;i++)
      cin>>b[i];
    sort(a,a+n);
    sort(b, b+n);
    for(i=0;i<n;i++)
    {
      min=a[i];
     if(a[i]>b[i])
        min=b[i];
     sum=sum+min;

    }
    cout<<sum<<endl;


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
