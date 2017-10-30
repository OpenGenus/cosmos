/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>
#include <windows.h>
#include <process.h>

void routine(void *a)
{
    int n = *(int *) a;
    Sleep(n);
    printf("%d ", n);
}

void sleepSort(int arr[], int n)
{
    int i;
    HANDLE threads[n];
    for (i = 0; i < n; i++)
        threads[i] = (HANDLE)_beginthread(&routine, 0, &arr[i]);
    WaitForMultipleObjects(n, threads, TRUE, INFINITE);
    return;
}

int main()
{
    int arr[] = {12, 23, 42, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    sleepSort (arr, n);

    return 0;
}
