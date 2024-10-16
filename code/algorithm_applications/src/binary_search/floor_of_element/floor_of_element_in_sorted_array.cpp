#include<bits/stdc++.h>
using namespace std; 
int solve(int arr[],int n,int ele){
  int ans=-1;
  int low=0;
  int high=n-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid]==ele){
      return ele; 
      }
    else if(arr[mid]<ele){
      ans=mid;
      low=mid+1;
      }
    else{
      high=mid-1;
      }
    }
  return arr[ans];
  }
int main(){
  int n;
  cin>>n; 
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    }
  int ele; 
  cin>>ele; 
  int ans=solve(arr,n,ele);
  cout<<"floor of "<<ele<<" is "<<ans<<endl; 
  return 0;
  }
