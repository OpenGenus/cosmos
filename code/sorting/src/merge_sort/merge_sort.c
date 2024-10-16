/*
 * Part of Cosmos by OpenGenus Foundation
 */

#include <stdio.h>

typedef int bool;

/* Merges two subhalves of a[].
    First sub-half is a[low..mid]
    Second sub-half is a[mid+1..high]
*/
void 
merging (int a[], int b[], int low, int mid, int high, bool order) 
{
    int l1, l2, i;
    
    /* Order 1 for sorting in Ascending order */
    if (order == 1) {
        /* Merge the two sub-halves into array b in sorted manner */
        for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {

            if (a[l1] <= a[l2]) {
                b[i] = a[l1++];
            }     
            else {
                b[i] = a[l2++];
            }
        }

        /* copy the remaining elements of the first sub-array (low-mid) , if any */
        while (l1 <= mid) {
            b[i++] = a[l1++];
        }
        
        /* copy the remaining elements of the second sub-array (mid+1-high), if any */
        while (l2 <= high) {
            b[i++] = a[l2++];
        }

        /* copy the entire modified array b back into the array a */
        for(i = low; i <= high; i++) {
            a[i] = b[i];
        }
    }

    /* Order 0 for sorting in Descending order */
    else if (order == 0) {
        /* Merge the two sub-halves into array b in sorted manner */
        for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {

            if (a[l1] >= a[l2]) {
                b[i] = a[l1++];
            }     
            else {
                b[i] = a[l2++];
            }
        }

        /* copy the remaining elements of the first sub-array (low-mid) , if any */
        while (l1 <= mid) {
            b[i++] = a[l1++];
        }
        
        /* copy the remaining elements of the second sub-array (mid+1-high), if any */
        while (l2 <= high) {
            b[i++] = a[l2++];
        }

        /* copy the entire modified array b back into the array a */
        for(i = low; i <= high; i++) {
            a[i] = b[i];
        }
    }

    /* If order not 0 or 1, sorting order undefined */
    else {
        printf("Undefined sorting order.\n");
    }
}

/* low is for left index and high is right index of the
   sub-array of a to be sorted */
void 
sort(int a[], int b[], int low, int high, bool order) 
{
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        //sort first and second halves
        sort(a, b, low, mid, order);
        sort(a, b, mid+1, high, order);
        merging(a, b, low, mid, high, order);
    } 

    else {
        return;
    }
}

int 
main() 
{
    int n;
    /* Take number of elements as input */
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int a[n];
    /* Take array elements as input */
    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    /* Declare new array to store sorted array */
    int b[n];

    bool order;
    /* Take sorting order as input */
    printf("Enter order of sorting (1: Ascending; 0:Descending)\n");
    scanf("%d", &order);
    
    /* If user does not enter 0 or 1 for order */
    if (order != 1 && order != 0) {
        printf("Undefined sorting order.\n");
        return 1;
    }

    sort(a, b, 0, n, order);

    /* Print final sorted array */
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return (0);
}
