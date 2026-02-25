#include <iostream>
#include<vector>
using namespace std;
    
int findlargestelement(vector<int> arr){
      int largest = arr[0];
   for(int i = 0; i < arr.size(); i++) {
      if(largest<arr[i]) {
         largest=arr[i];
      }
   }
   return largest;

    
}
int main() { 
   vector<int> arr;
   cout << "Enter array elements: ";
    
   for(int i = 0; i < arr.size(); i++){
      cin >> arr[i];
   }
   int largest = findlargestelement(arr);
   cout << " Largest Element is: " << largest;
    
   return 0;
}
