// Lecture 1 of Aditya Verma of the sliding window problem of series
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int maximum_sum_subarray(int arr[],int n,int k){
    int i=0;
int mx=INT_MIN;
    int j=0;
    int sum=0;
    while(j<n){
      // work first make the window if the size is less than window size
      sum+=arr[j];
      if((j-i+1)<k){
        j++;
      }
      else if((j-i+1)==k){
      mx=max(mx,sum);
      sum=sum-arr[i];

      i++;
      j++;
      }



    }

return mx;
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
int arr[100];
fi(0,6)cin>>arr[i];
cout<<maximum_sum_subarray(arr,6,3);
return 0;
}