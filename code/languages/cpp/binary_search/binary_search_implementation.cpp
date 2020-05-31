/* Part of Cosmos by OpenGenus Foundation */
// Iterative Approach
#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int sorted_array[], int left, int right, int element) 
{ 
     while (left <= right) 
    { 
        int middle = (left + right) / 2; 
        // Check if element is present at middle position or not 
        if (sorted_array[middle] == element) 
            return middle; 
        // If element is greater, ignore left half 
        if (sorted_array[middle] < element) 
            left = middle + 1; 
        // If element is smaller, ignore right half 
        else
            right = middle - 1; 
    } 
    // if element is not present then return -1 
    return -1; 
}
int main()
{
    int a[] = { 10, 12, 20, 32, 50, 55, 65, 80, 99 };
    int element = 12;
    int size = sizeof(a) / sizeof(a[0]); 
    sort(a, a + size);
    int result = BinarySearch(a, 0, size - 1, element); 
    if(result == -1)
        cout<<"Element is not present in array";
    else
        cout<<"Element is present at index "<< result;
    return 0;
}

// Recursive Approach
#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int sorted_array[], int left, int right, int element) 
{ 
    if (right >= left) 
    { 
        int middle = (left + right) / 2; 
        // If the element is present at the middle itself 
        if (sorted_array[middle] == element) 
            return middle; 
        // If element < middle, then it can only be present in left subarray 
        if (sorted_array[middle] > element) 
            return BinarySearch(sorted_array, left, middle - 1, element); 
        // Else the element can only be present in right subarray 
        return BinarySearch(sorted_array, middle + 1, right, element); 
    } 
    // We reach here when element is not 
    // present in array 
    return -1;  
} 
int main()
{
    int a[] = { 1, 5, 7, 3, 4, 8, 2, 9, 6 };
    int element = 5;
    int size = sizeof(a) / sizeof(a[0]); 
    sort(a, a + size);
    int result = BinarySearch(a, 0, size - 1, element); 
    if(result == -1)
        cout<<"Element is not present in array";
    else
        cout<<"Element is present at index "<< result;
    return 0;
}

// STL Function
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = { 10, 12, 20, 32, 50, 55, 65, 80, 99 };
    int element = 12;
    int size = sizeof(a) / sizeof(a[0]); 
    sort(a, a + size);
    if (binary_search(a, a + size, element)) 
        cout << "\nElement found in the array"; 
    else
        cout << "\nElement not found in the array"; 
    return 0;
}
