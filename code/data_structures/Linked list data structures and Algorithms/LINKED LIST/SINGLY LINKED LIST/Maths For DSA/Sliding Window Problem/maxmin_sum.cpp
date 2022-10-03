// we want a window of given size and we want maximum sum of all windows and find the max su

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
pair<int,int> max_min_sliding_window(int arr[],int size,int window_size){
 int s=0,e=0,sum=0,mx=INT_MIN,mn=INT_MAX;
 while (e<size)
 {
    sum+=arr[e];
  // we will increase the size of the window till k as we have to find that given size only
  int curr_window_size=e-s+1;
  if(curr_window_size<window_size)e++;
  else if(curr_window_size==window_size){
    // we will perform the calculation which was given in the question for the subarray of given size
    mx=max(sum,mx);
    mn=min(sum,mn);
    // now keep the window size constant we have to do the following steps
    //1) remove the start element form the sum 
    sum-=arr[s];
    // 2) we heve to increent the back as well as front side of the window to keep it constant
    s++;
    e++;

  }
 }
    pair<int,int>p;
    p.first=mx;
    p.second=mn;
    return p;
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[100];
  int n,k;
  cin>>n>>k;
fi(0,n)cin>>arr[i];
cout<<max_min_sliding_window(arr,n,k).first<<" "<<endl;

cout<<max_min_sliding_window(arr,n,k).second<<" "<<endl;
return 0;
}
