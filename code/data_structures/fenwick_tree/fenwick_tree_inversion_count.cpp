#include <bits/stdc++.h>
using namespace std;


typedef int ll;
ll BIT[101000], A[101000],n;

ll query(int i){
	ll ans = 0;
	for(;i > 0;i-=i&(-i)){
		ans += BIT[i];
	}
	return ans;
}
ll update(int i){
	for(;i <=n;i += i&(-i))
		BIT[i]++;
}
inline void scanint(ll *x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}


main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	ll ans,i;
	while(cin >> n and n){
		memset(BIT,0,(n+1)*(sizeof(ll)));
		for(int i=0;i<n;i++){
			scanint(&A[i]);
		}
		ans = 0;
		for(i=n-1;i>=0;i--){
			ans += query(A[i]-1);
			update(A[i]);
		}
		cout << ans << endl;
	}
}
