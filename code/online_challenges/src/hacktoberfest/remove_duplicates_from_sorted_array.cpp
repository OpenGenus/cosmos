// C++ program to remove duplicates from a sorted array in-place
#include<iostream>
using namespace std;
 

int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;

    int j = 0;

    for (int i=0; i < n-1; i++)
        if (arr[i] != arr[i+1])
            arr[j++] = arr[i];
 
    arr[j++] = arr[n-1];
 
    return j;
}