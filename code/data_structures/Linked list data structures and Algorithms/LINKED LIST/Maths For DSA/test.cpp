#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
int a[]={1,2,3,4,5};
int sum=0;
for (int i = 0; i < 5; i++)
{
  if(i%2==0){
    sum+=a[i];
  }
}
cout<<sum;
return 0;
}
