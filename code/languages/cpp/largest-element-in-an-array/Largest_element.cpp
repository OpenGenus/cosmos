#include <iostream>
using namespace std;

// Function to find the largest element in the array
int findlargestelement(int arr[], int n){

   // Assume the first element is the largest initially
   int largest = arr[0];

   // Traverse the entire array
   for(int i = 0; i < n; i++) {

      // If current element is greater than the current largest
      if(largest < arr[i]) {

         // Update the largest value
         largest = arr[i];
      }
   }

   // Return the largest element found
   return largest;
}

int main() {

   int n;

   // Ask user for the size of the array
   cout << "Enter the size of array: ";
   cin >> n; 

   // Declare an array of size n
   int arr[n];

   // Take array elements as input from the user
   cout << "Enter array elements: ";
   for(int i = 0; i < n; i++){
      cin >> arr[i];
   }

   // Call the function to find the largest element
   int largest = findlargestelement(arr, n);

   // Print the largest element
   cout << "Largest Element is: " << largest;

   return 0;
}
