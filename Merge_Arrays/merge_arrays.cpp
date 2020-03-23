#include<stdlib.h>
#include<iostream>
using namespace std;

void merge(int arr[], int arr1[], int arr2[], int n1, int n2)
{
    int k=0;
    for(int i = 0; i < n1; i++)
    {
        arr[k] = arr1[i];
        k++;
    }
    for(int i = 0; i < n2; i++)
    {
        arr[k] = arr2[i];
        k++;
    }
}

int main()
{
    int n1,n2;
    cout << "Enter the size of array 1 : \n";
    cin >> n1;
    cout << "Enter the size of array 2: \n";
    cin >> n2;
    int arr1[n1], arr2[n2], arr[n1+n2];
    cout << "Enter the values for array1 : \n";
    for(int i = 0;i < n1; i++)
        cin >> arr1[i];
    cout << "Enter the values for array2 : \n";
    for(int i = 0;i < n2; i++)
        cin >> arr2[i];
    merge(arr, arr1, arr2, n1, n2);
    cout << "Merged array : \n";
    for(int i = 0;i < n1+n2; i++)
        cout << arr[i] <<"\t";
}

