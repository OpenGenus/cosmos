#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int fibonacci(int n){
    if(n<=1)return n;
    return fibonacci(n-1)+fibonacci(n-2);

    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
int n=5
;
cout<<fibonacci(n);
return 0;
}
