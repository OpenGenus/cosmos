// C++ program to impleament cycle sort
#include <bits/stdc++.h>
using namespace std;

// Function sort the array using Cycle sort
void cycleSort (int arr[], int n)
{
    int writes = 0;


    for (int cycle_start=0; cycle_start<=n-2; cycle_start++)
    {

        int item = arr[cycle_start];


        int pos = cycle_start;
        for (int i = cycle_start+1; i<n; i++)
            if (arr[i] < item)
                pos++;


        if (pos == cycle_start)
            continue;

        while (item == arr[pos])
            pos += 1;

        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }

        while (pos != cycle_start)
        {
            pos = cycle_start;

            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos += 1;

            while (item == arr[pos])
                pos += 1;

            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }

}

// Driver program to test above function
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,15,48,92,65,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cycleSort(arr,  n) ;

    cout << "After sort : " <<endl;
    for (int i =0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
