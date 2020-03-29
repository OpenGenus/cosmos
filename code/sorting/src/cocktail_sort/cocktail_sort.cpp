#include <iostream>
/* cocktail sort is similar to the bubble sort but with less complexity
 * comparatively */
int *cocktailsort(int a[], int len) {
    /* first variable represent the starting index of the array */
    int first = 0;
    /* temp variable is used to exchange values */
    int temp = 0;
    /* last variable represent the ending index of the array */
    int last = len - 1;
    /* flag variable checks if the array contains sorted elements after sorting
     * process */
    int flag = 1;
    while (flag != 0) {
        flag = 0;
        for (int i = first; i < last; ++i) {
            /* this for loop do the forward sorting on the array */
            if (a[i] > a[i + 1]) {
                /* larger element is exchanged with smaller one */
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                flag = 1;
            }
            /* after each process, largest element is at the last index and flag
             * is set to 1 */
        }
        if (!flag) {
            /* if flag is not 1, it means the array is sorted already, so the
             * control is sent out of while loop */
            break;
        } else {
            /* last is decreased by 1 as largest element need not to be sorted
             */
            flag = 0;
            last--;
        }
        for (int i = last; i >= first; --i) {
            /* this for loop do backward sorting on the array */
            if (a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                flag = 1;
            }
        }
        /* the smallest element is placed at the front of the array, so the
         * value of first variable is increased by 1 */
        first++;
    }
    /* the pointer to the sorted array is passed */
    return a;
}

int main() {
    /* a represent the unsorted array */
    int a[] = {998, 40, 80, 0, 2, 16, 2, 40};
    /* len variable represent the length of array */
    int len = sizeof(a) / sizeof(a[0]);
    /* cocktailsort function is called with parameters array a and length
     * of array len */
    int *ptr = cocktailsort(a, len);
    for (int i = 0; i < len; ++i) {
        /* this for loop display the sorted array elements */
        std::cout << ptr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

/* output: 0 2 2 16 40 40 80 998 */
