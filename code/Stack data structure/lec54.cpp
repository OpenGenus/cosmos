#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
stack<ll>s;
s.push(56);
s.push(4);
s.push(32);
s.push(43);
s.push(2);
s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
cout<<s.top();  
if(s.empty())cout<<"Stack is empty"<<endl;
else
cout<<"Stack is not empty"<<endl;

return 0;
}
