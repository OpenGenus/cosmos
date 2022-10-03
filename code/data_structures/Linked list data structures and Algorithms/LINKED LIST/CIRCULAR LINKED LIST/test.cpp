#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int power(int a,int b){
  if(a==1||b==1){
    return a;
  }
  if(b==0)return 1;
  if(a==0)return 0;
  
  return a*power(a,b-1);

}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
cout<<power(2,0);
return 0;
}
