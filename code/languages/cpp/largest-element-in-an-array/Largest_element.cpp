#include <iostream>
using namespace std;
    
int findlargestelement(int arr[], int n){
      int largest = arr[0];
   for(int i=0; i<n; i++) {
      if(largest<arr[i]) {
         largest=arr[i];
      }
   }
   return largest;
}
int main() {
   int n;
   cout<<"Enter the size of array: ";
   cin>>n; 
   int arr[n];
   cout<<"Enter array elements: ";
   for(int i=0; i<n; i++){
      cin>>arr[i];
   }
   int largest = findlargestelement(arr, n);
   cout<<"largest Element is: "<<largest;
   return 0;
}
