//Implementation of Bubble Sort using recursion
#include<stdlib.h>
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

void bubble_sort(int a[], int n)
{
    if(n == 1)
        return;
    //The largest element is bubbled to the end in the first pass
    for(int i = 0; i < n; i++)
    {
        if(a[i] > a[i + 1])
            swap(a[i],a[i+1]);
    }

    //Recursively do for rest of the (n-1) elements
    bubble_sort(a, n - 1);
}

int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;
    int a[n];
    cout << "Enter the values for the array\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    bubble_sort(a,n);

    //printing the array after sorting
    for(int i = 0; i < n; i++)
        cout << a[i] << "\t";
    return 0;
}

/* Sample Input - Output
Enter the size of the array
5
Enter the values for the array
12 14 31 16 11
11	12	14	16	31	
*/