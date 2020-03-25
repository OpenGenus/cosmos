#include<iostream>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,i,k,x,sum=0;
        cin>>n>>k;
        for(i=0;i<n;i++){
            cin>>x;
            sum+=x;
        }
        sum=sum%k;
        cout<<sum<<"\n";
    }
    return 0;
}