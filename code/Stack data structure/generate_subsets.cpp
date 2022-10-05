#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)


vector<vector<int>> subset_store(vector<int>&nums){
    int n=nums.size();
    int subsets_ct=(1<<n);
    // create bit mask from 0 to subsets_ct 
    // here understand mask as mask not as iterator
    vector<vector<int>>subsets;
    for (int mask = 0; mask < subsets_ct; ++mask)
    {
        // create a vector<int> to sotre temporary subsets and then finnaly store it to ans
        vector<int>subset;
        // now we go to each mask and check is ith bit is set or not
          for (int i = 0; i < n; ++i)
          {
            if((mask&(1<<i))!=0){
                // this means arr_bit_indexth bit is set means arr_bit_index index is present
                
                       subset.push_back(nums[i]);
            }
            
          }
          
        subsets.push_back(subset);
    }
    return subsets;

}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>v;
for (int i = 0; i < n; i++)
{
    int x;
    cin>>x;
    v.push_back(x);
}

auto all_subsets=subset_store(v);

for(auto in:all_subsets){
    for(auto j:in){
        cout<<j<<" ";
    }
    cout<<endl;
}



return 0;
}