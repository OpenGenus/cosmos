#include <iostream>
using namespace std; 
// Brick sort is a similar to bubble sort in terms of sorting array. 
// It sorts the array in terms of odd and even index places elements. 
void BrickSort(int l[], int n)
{
    /* l is the arguement used that contains the unsorted element 
     * n is the variable that contains the no. of elements in the array 
     * sort variable is used to denote if array is sorted after the sorting process. 
     * it is initialised 0 to check if array is sorted after every iteration
     */ 
    int sort = 0;
    while (sort == 0)
    {
        // sort is set to 1  when loop conditions is true 
        sort = 1;
        // this for loop sorts the even indexed element in an array 
        int temp = 0;
        for (int i = 0; i <= n - 2; i = i + 2)
        {
            if (l[i] > l[i + 1]) 
            {
                temp = l[i];
                l[i] = l[i+1];
                l[i+1] = temp;
                sort = 0;
            }
        }
        // sort is set to 0 whenever loop is executed 
        // the next loop sorts the odd indexed element in the array 
        for (int i = 1; i <= n - 2; i = i + 2)
        {
            if (l[i] > l[i + 1]) 
            {
                temp = l[i];
                l[i] = l[i+1];
                l[i+1] = temp;
                sort = 0;
            }
        }
    }        

    // array is returned once it is sorted 
    for (int i = 0; i < n; ++i) 
    // for loop is used to display the sorted array elements 
        cout << l[i] << " "; 
    cout << "\n";
}

int main()
{
    //  sample array with unsorted elements
    int l[]= {4, 2, 1, 6, 4, 67, 23, 11, 9};
    int n = sizeof(l) / sizeof(l[0]);
    BrickSort(l, n);
    return 0;
}
// output-> 1 2 4 4 6 9 11 23 67 
