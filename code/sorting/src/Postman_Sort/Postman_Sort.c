// C Program to Implement Postman Sort Algorithm

#include <stdio.h>

void arrange(int, int);
int arr[100], arr1[100];
int i, j, temp, max, count, maxdigits = 0, c = 0;

void main()
{
    int t1, t2, k, t, n = 1;

    printf("Enter size of array :");
    scanf("%d", &count);
    printf("Enter elements into array :");
    for (i = 0; i < count; i++)
    {
        printf("Element - %d : ", i);
        scanf("%d", &arr[i]);
        arr1[i] = arr[i];
    }

    //Finding the longest digits in the array and no of elements in that digit
    for (i = 0; i < count; i++)
    {
        t = arr[i]; /*first element in t */
        while (t > 0)
        {
            c++; //Counting the no of elements of a digit
            t = t / 10;
        }
        if (maxdigits < c)
            maxdigits = c; //Storing the length of longest digit
        c = 0;
    }
    while (--maxdigits)
        n = n * 10;

    for (i = 0; i < count; i++)
    {
        max = arr[i] / n; //Dividing by a particular base
        t = i;
        for (j = i + 1; j < count; j++)
        {
            if (max > (arr[j] / n))
            {
                max = arr[j] / n;
                t = j;
            }
        }
        temp = arr1[t];
        arr1[t] = arr1[i];
        arr1[i] = temp;
        temp = arr[t];
        arr[t] = arr[i];
        arr[i] = temp;
    }
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            t1 = arr[i] / n;
            for (j = i + 1; t1 == (arr[j] / n); j++)
                ;
            arrange(i, j);
            i = j;
        }
        n = n / 10;
    }
    printf("\nSorted Array (Postman sort) :");
    for (i = 0; i < count; i++)
        printf("%d ", arr1[i]);
    printf("\n");
}

//Arranging the elements
void arrange(int k, int n)
{
    for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr1[i] > arr1[j])
            {
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
                temp = (arr[i] % 10);
                arr[i] = (arr[j] % 10);
                arr[j] = temp;
            }
        }
    }
}
/* Enter the Size of the array
6
Enter the elements of the array
Element - 0 : 43
Element - 1 : 35
Element - 2 : 75
Element - 3 : 1
Element - 4 : 68
Element - 5 : 453
Sorted Array
1  35  43  68  75  453  */