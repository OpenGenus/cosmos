// Coin change to compute minimum number of coins needed to change some value

#include <bits/stdc++.h>

using namespace std;

int N;
int DP[1000],coinvalue[1000];

int coin(int value){
	int zz;
	if(value==0) return 0;
	if(value<0) return 1000000;
	if(DP[value]==-1){
		int mini=1000000;
		for(int i=0;i<N;i++){
			zz=coin(value-coinvalue[i]);
			if(mini>zz)mini=zz;
		}
		DP[value]=1+mini;
	}
	return DP[value];
}

int main(){
	int value;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> coinvalue[i];
	}
	cin >> value;
	memset(DP,-1,sizeof DP);
	int ans;
	ans = coin(value);
	cout << ans << endl;
} 
