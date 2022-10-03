// sort a list based of the middle elements
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
list<ll>l;
int n;
cin>>n;
for (int i = 0; i < n; i++)
{
    ll x;
    cin>>x;
    l.push_back(x);
}
l.sort();
for (auto const &i: l) {
        std::cout << i << std::endl;
    }
return 0;
}
