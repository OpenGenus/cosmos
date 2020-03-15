#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define int ll
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

 
main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int t,i;
	cin>>t;
	vector<pair<int,int> > vec;
	for(i=0;i<6;i++){
		vec.push_back({i*250000,(i+1)*250000});
	}
	vec.push_back({i*250000,inf});
	while(t--){
		int n,ans,diff;
		cin>>n;
		ans=n;
		for(i=0;i<vec.size();i++){
			diff=min(vec[i].second,n)-vec[i].first;
			ans-=diff*i*5/100;
			if(n<=vec[i].second){
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 