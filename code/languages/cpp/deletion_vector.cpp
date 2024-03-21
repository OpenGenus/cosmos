@@ -0,0 +1,26 @@
//deleting an element from the array using vector
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void main()
{
  int n,de;
  vector <int> v;
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
  cout<<"enter which no element you want to delete"<<endl;
  cin>>de;
  v.erase(v.begin()+de-1);
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<" ";
  }
}
