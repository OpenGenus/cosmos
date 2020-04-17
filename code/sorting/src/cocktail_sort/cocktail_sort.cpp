#include <iostream>

/* Cocktailsort is similar to the bubble sort but the complexity is less comparatively. */
void cocktail_sort(int l[], int n)
{
    int first = 0, temp = 0, last = n - 1, p = 1;
    while (p != 0)
    {
        /* while loop checks the status of the array */
        p = 0;
        for (int i = first; i < last; ++i)
        {
            /* for loop is used to do the forward sorting on the array */
            if (l[i] > l[i + 1])
            {
                temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
                p = 1;
            }
            /* after every sorting, largest element is at the last index and value of p is set to 1 */
        }
        if (!p)
            /* if value is not 1, it means the array is sorted already , so the control is sent out of while loop */
            break;
        else
        {
            p = 0;
            last--;
        }
        for (int i = last; i >= first; --i)
        {
            if (l[i] > l[i + 1])
            {
                temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
                p = 1;
            }
        }
        first++;
    }
    //Displaying
    for (int i = 0; i < n; ++i)
        std::cout << l[i] << " ";
}

int main()
{
    int unsorted_array[] = {5, 1, 4, 2, 8, 0, 2};
    int n = sizeof(unsorted_array) / sizeof(unsorted_array[0]);
    cocktail_sort(unsorted_array, n);
    return 0;
}

/*
Sample Input:
5 1 4 2 8 0 2

Sample Output:
0 1 2 2 4 5 8
*/