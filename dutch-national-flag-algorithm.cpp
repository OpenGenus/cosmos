// The Dutch National Flag algorithm or three-way partitioning algorithm allows sorting the
// array consisting of 0s, 1s, and 2s in a single traversal only and in constant space.
// Steps:
// ● Maintain three indices low = 0, mid = 0, and high = N-1, where N is the number of
// elements in the array.
// 1. The range from 0 to low denotes the range containing 0s.
// 2. The range from low to mid denotes the range containing 1s.
// 3. The range from mid to high denotes the range containing any of 0s, 1s, or 2s.
// 4. The range from high to N-1 denotes the range containing 2s.
// ● The mid pointer denotes the current element, traverses the array while mid<=high i.e
// we have exhausted the search space for the range which can contain any of 0s, 1s,
// or 2s.
// 1. If A[mid] == 0, swap A[mid] and A[low] and increment low and mid pointers by
// 1.
// 2. If A[mid] == 1, increment the mid pointer by 1.
// 3. If A[mid] == 2, swap A[high] and A[mid] and increment mid by 1 and
// decrement high by 1.
// The resulting array will be a sorted array containing 0s, 1s, and 2s.
#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void sort012(int *arr, int n)
{
    //Dutch National Flag Algorithm
    int low=0,mid=0,high=n-1;
    int temp;
    while (mid<=high){
        if(arr[mid]==0){
            temp=arr[mid];
            arr[mid]=arr[low];
            arr[low]=temp;
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            temp=arr[mid];
            arr[mid]=arr[high];
            arr[high]=temp;
            high--;
//             
        }
        
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }
    sort012(arr,n);
    print(arr,n);
    return 0;
}