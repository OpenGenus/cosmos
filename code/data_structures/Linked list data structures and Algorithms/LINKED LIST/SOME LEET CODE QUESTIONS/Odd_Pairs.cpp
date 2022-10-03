#include <iostream>
using namespace std;
#define ll long long
ll number_of_required_pairs(int N){
    ll ct=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==0 && j==0)
            return 0;
            if(i>=1 && j>=1 && i<=N &&j<=N && (i+j)%2!=0)
            ct++;
        }
    }
    return ct;
}
int main() {
	// your code goes here
	 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	  ll N;
	  cin>>N;
	  cout<< number_of_required_pairs(N)<<endl;
	}
	return 0;
}
