#include <bits/stdc++.h> 
using namespace std; 
  
// Returns number of pairs in arr[0..n-1] with sum equal to 'sum' 
int getPairsCount(int arr[], int n, int sum) 
{ 
    int count = 0; 
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i]+arr[j] == sum) 
                count++; }}
        return count; 
} 
  
// Driver function to test the above function 
int main() 
{ 
    int n; cin>>n;
    int arr[n], sum=0;
    for(int i=0;i<n;i++)
     cin>>arr[i];
    cout << getPairsCount(arr, n, sum); 
    return 0; 
} 
