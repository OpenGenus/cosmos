#include <iostream>
using namespace std;

void stoogesort(int arr[],int l, int h)
{
    if (l >= h)
      return;
 
    if (arr[l] > arr[h])
       swap(arr[l], arr[h]);
 

    if(h-l+1>2)
    {
        int t = (h-l+1)/3;
 

        stoogesort(arr, l, h-t);

        stoogesort(arr, l+t, h);
 
        stoogesort(arr, l, h-t);
    }
}
 

int main()
{
    int arr[] = {2, 4, 5, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
 

    stoogesort(arr, 0, n-1);

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 
    return 0;
}