#include<bits/stdc++.h>
using namespace std;
int peakIdxMountainArray(vector<int>& nums) {
       int s=0,e=nums.size()-1;
       int m=s+(e-s)/2;
        while(s<e){
          
            if(nums[m]<nums[m+1])
                s=m+1;
            else
                e=m;
             m=s+(e-s)/2;
        }
        return s;
    }



int main(){
  vecctor<int>nums;
  int n,x;
  cin>>n;
 
  for(int i=0;i<n;i++){
    cin>>x;
    nums.push_back(x);
  }
  int p;
  p=peakIdxMountainArray(nums);
  cout<<p<<endl;
 
  
}
