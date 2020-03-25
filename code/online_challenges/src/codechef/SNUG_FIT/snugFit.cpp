#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,i,sum=0;
        cin>>n;
        ll a[n],b[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        for(i=0;i<n;i++){
            sum+=min(a[i],b[i]);
        }
        cout<<sum<<"\n";
    }
    return 0;
}