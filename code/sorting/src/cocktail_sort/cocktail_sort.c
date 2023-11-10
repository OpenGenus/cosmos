#include <stdio.h>
/* CocktailSort function is the function used to sort the array using cocktail algorithm. */
/* Cocktailsort is similar to the bubble sort but the complexity is less comparatively. */
void cocktailsort(int l[], int n)  
{   
    /* argument passed is the list of the array to be sorted and the length of the array */

    /* first is used to represent the starting index of the array */
    int first = 0; 
    int temp = 0;
    /* last is used to represent the last index of the array */
    int last = n - 1;
    /* p is the variable used to check if the array contains sorted elements after sorting process */
    int p = 1;
    while ( p != 0) 
    {
        /* while loop checks the status of the array */
        p = 0;
        for (int i = first; i < last; ++i) 
        { 
        /* for loop is used to do the forward sorting on the array */
            if (l[i] > l[i + 1]) 
            { 
                /* larger element is exchanged with smaller one */
                temp = l[i];
                l[i] = l[i+1];
                l[i+1] = temp;
                p = 1; 
            }
            /* after every sorting, largest element is at the last index and value of p is set to 1 */
        } 
        if (! p)
        /* if value is not 1, it means the array is sorted already , so the control is sent out of while loop */
            break;
        else 
        {
        /* value of last is decreased by 1 as largest element need not to be sorted */
            p = 0;
            last--;
        }
        for (int i = last; i >= first; --i) 
        { 
        /* for loop is used to do backward sort on the array */
            if (l[i] > l[i + 1]) 
            { 
                temp = l[i];
                l[i] = l[i+1];
                l[i+1] = temp;
                p = 1; 
            } 
        }
        /* the smallest element is placed at the front of the array, so the value of first variable is increased by 1 */
        first++;
    }
    for (int i = 0; i < n; ++i) 
    /* for loop is used to display the sorted array elements */
        printf("%d ", l[i]); 
    printf("\n");
}

int main() 
{   /* l represents the unsorted array */
    int l[] = { 5, 1, 4, 2, 8, 0, 2 }; 
    /* n variable is used to count the length of array */
    int n = sizeof(l) / sizeof(l[0]);
    /* cocktailsort function is called in order with parameters l and length of array n */
    cocktailsort(l,n); 
    return 0;
} 

/* output-> 0 1 2 2 4 5 8 */