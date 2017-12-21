#include <stdio.h>

int 
min(int a, int b)
{
    return (a < b ? a : b);
}

int 
binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return (mid);
 
        if (arr[mid] > x)
            return (binarySearch(arr, l, mid - 1, x));
 
        return (binarySearch(arr, mid + 1, r, x));
    }

    return (-1);
}
 
int 
exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return (0);
 
    int i = 1;

    while (i < n && arr[i] <= x)
        i = i*2;

    return (binarySearch(arr, i / 2, min(i, n), x));
}
 
int 
main()
{
   int n;
   printf("Enter size of Array \n");
   scanf("%d", &n);

   int arr[n], i;
   printf("Enter %d integers in ascending order \n", n);
   for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

   int x;
   printf("Enter integer to be searched \n");
   scanf("%d", &x);

   int result = exponentialSearch(arr, n, x);

   if (result == -1)
        printf("%d is not present in array \n", x);
   else
        printf("%d is present at index %d \n", x, result);

   return (0);
}