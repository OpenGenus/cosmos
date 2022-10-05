#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
stack<char>s;
char ch[500];
for (int i = 0; i < 5; i++)
{
    cin>>ch[i];
}

for (int i = 0; i < 5; i++)
{
   char sh=ch[i];
s.push(sh);
}
cout<<s.top()<<" ";


return 0;
}
