// power of any number optimised approach
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int power(int a,int b){
    if(b==0)return 1;
    int x=power(a,b/2);
    if(b%2==0)return x*x;
    else
    return a*x*x;
}
int power_it(int a,int b){
    int ans=1;
    while (b>0)
    {
        if(a%2==1){
            ans=ans*a;
        }
        b=b/2;
        a=a*a;

    }
    return ans;
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
int a,b;
cin>>a>>b;
cout<<power_it(a,b);
return 0;
}
