// implementation of quicksort using randomization
// by shobhit(dragon540)
#include <algorithm>
#include <ctime>
#include <iostream>

void quicksort(int arr[], int i, int n);
int part(int arr[], int low, int high);

int main() 
{
        srand(time(NULL));
        int arr[10] = {-25, 119, 32, 54, 623, 20, -2, -4, 8, 11};
        
        // sorts the array in increasing order
        quicksort(arr, 0, 9);
        
        for(int i=0; i < 10; i++) 
       	    std::cout << arr[i] << " ";
            
        std::cout << '\n';
        return 0;
}
void quicksort(int arr[], int low, int high) 
{
    if(low < high)
    {
         int pi = part(arr, low, high);

         quicksort(arr, low, pi-1);
         quicksort(arr, pi+1, high);
    }
}
// sort a sub array in increasing order
int part(int arr[], int low, int high)
{
     int pivotIndex = low + (rand() % (high - low + 1));
     int pivot = arr[pivotIndex];
     int l = low - 1;
        
     std::swap(arr[pivotIndex], arr[high]);
        
    for(int i = low; i < high; i++) 
    {
	    if(arr[i] < pivot) 
	    {
		    ++l
             std::swap(arr[l],arr[i]);
          }
    }    
        std::swap(arr[l+1],arr[high]);
        
    return l+1;
}
