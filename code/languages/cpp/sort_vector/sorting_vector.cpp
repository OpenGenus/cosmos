//sorting using vectors
#include<bits/stdc++.h>
using namespace std;
int main;
{
  vector<int> v;
  cout<<"size of array"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    v.push_back(i);
  }
  for(int i=0;i<n;i++)
  {
    cout<<v[i]<<" ";
  }
  sort(v.begin(),vec.end());
  for(int x:v)
  {
    cout<<x<<" ";
  }
  return 0;
}
