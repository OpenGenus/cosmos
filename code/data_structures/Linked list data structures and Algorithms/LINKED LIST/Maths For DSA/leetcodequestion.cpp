#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
int a;
cin>>a;
int i=0;
int ans=0;
while(a>0){
    int digit=a%10;
  ans=ans+digit*pow(10,i);

    a/=10;
    i++;
}
cout<<ans;

return 0;
}
