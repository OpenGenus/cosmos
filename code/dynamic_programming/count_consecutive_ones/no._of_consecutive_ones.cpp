#include<bits/stdc++.h>
using namespace std;
void fast() {std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long
#define pb push_back
#define mp1 make_pair
#define ff first
#define ss second
#define vi vector<int>
#define vii vector< pair<int,int> >
#define map map<ll int,ll int>
#define vll vector< pair<long long,long long> > 
#define ve vector<ll int>
#define clr(x) memset(x, 0, sizeof(x))
#define loop(x,a,b) for(x=a;x<b;x++)
#define rloop(x,a,b) for(x=a;x>=b;x--)
#define itr for(std::map<ll int,ll int>::iterator it=mp.begin(); it!=mp.end(); ++it)
const int mod=1e9+7;
const int maxn=1e6+5;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	ll int a,b,c,d,i,j,sum=0,cnt=0;
	string s;
	ve v;
	s="11000001111110101111010";
	loop(i,0,s.size())
	{
		if(s[i]=='1')
		{
			sum++;
		}
		else
		{
			v.pb(sum);
			sum=0;
		}
	}
	sort(v.rbegin(),v.rend());
	cout << v[0] << endl;
}