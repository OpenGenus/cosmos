//This program will return the peak element index in a mountain array
#include <iostream>
using namespace std;

// function code
int peakIndexInMountainArray(int arr[],int size){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while(start<end){
        if(arr[mid]<arr[mid+1])
            start=mid+1;
        else
            end=mid;
        mid=start+(end-start)/2;
        }
    return start;
}

//driver code
int main(){
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int arr[n];
    //taking input in the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   int ans= peakIndexInMountainArray(arr,n);
   cout<<ans<<endl;

    return 0;

}
