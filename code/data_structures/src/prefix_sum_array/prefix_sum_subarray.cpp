// Part of Cosmos by OpenGenus
//Max Sum Subarray in O(n)
#include <bits/stdc++.h>
using namespace std;
int maximumSumSubarray(int *arr, int n){
   int minPrefixSum = 0;
   int res = numeric_limits<int>::min();
   int prefixSum[n];
   prefixSum[0] = arr[0];
   for (int i = 1; i < n; i++) {
      prefixSum[i] = prefixSum[i - 1] + arr[i];
   }
   for (int i = 0; i < n; i++) {
      res = max(res, prefixSum[i] - minPrefixSum);
      minPrefixSum = min(minPrefixSum, prefixSum[i]);
   }
   return res;
}
int main(){
	int n;
	cin>>n; // size of the array
    int arr[n];
    for(int i=0;i<n;i++){   //input array
    	cin>>arr[i];
    }
	cout << "Result = " << maximumSumSubarray(arr, n) <<endl;
	return 0;
}
