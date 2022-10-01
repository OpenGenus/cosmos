// C++ code to linearly search x in arr[].
//If x is present then return its location, otherwise return -1

#include <iostream>
using namespace std;

int *linearSearch(int arr[], int result[], int N, int x)
{
    int pos = -1, ind = 0;
    for (int i = 0; i <N; ++i)
    {
        if (arr[i] == x)
        {
            result[ind++] = i+1; // store the index of key, if found
        }
        else
            result[ind++] = -1; // store -1 if key not found
    }
    return result;
}

// Driver's code
int main(void)
{
    int arr[] = {2, 3, 4, 10, 40, 3, 10, 2, 10 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);
    int result[N];
    linearSearch(arr, result, N, x);
    int size = sizeof(result) / sizeof(result[0]);
    cout<<"Key found at position(s) : \n";
    for (int i = 0; i < size; i++)
    {
        if (result[i] != -1)
            cout<<result[i]<<" ";
    }
    return 0;
}



