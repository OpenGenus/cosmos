#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
void func(vector<int>&v,int val){
for (auto it=v.begin();it!=v.end();++it)
{
  if((*it)==val)
  v.erase(it);
}

    fi(0,v.size()){
      cout<<v[i];
    }
   }


int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
vector<int>v;
int n;cin>>n;
fi(0,n){
    int x;
    cin>>x;
    v.push_back(x);
}
int val;
cin>>val;
func(v,val);
return 0;
}
