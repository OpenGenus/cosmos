#include <stdio.h>

/*
Input : integer array indexed from 0, key to be searched
Output : Position of the key in the array if found, else -1
*/

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            return i;  // key found
        }
    }
    return -1;  // key not found
}

int main()
{
    int arr[] = {8, 12, 3, 4, 7, 2, 13};
    int size = sizeof(arr) / sizeof(arr[0]);

    int pos = linearSearch(arr, size, 12);

    if (pos != -1)
        printf("Key found at position : %d\n", pos);
    else
        printf("Key not found\n");

    return 0;
}
