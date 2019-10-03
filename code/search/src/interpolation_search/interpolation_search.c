#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
int interpolationSearch(int* array, int n, int key){
    int high = n-1;
    int low = 0;
    int mid;

    while ( (array[high] != array[low]) && (key >= array[low]) && (key <= array[high])) {
        mid = low + (int)( ((float)(high-low) / (array[high] - array[low])) * (key - array[low]) );

        if(array[mid] == key)
            return mid;

        else if (array[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;

    }
    return -1;
}

void test(){

    // Array of items on which search will be conducted.
    int array[10] = {1, 5, 9, 12, 16, 18, 25, 56, 76, 78};
    int n = sizeof(array)/sizeof(array[0]);

    // Element to be searched
    int key = 25;

    int index = interpolationSearch(array, n, key);

    if(index !=-1)
        printf("Element found at index %d\n", index);
    else
        printf("EElement not found.\n");
}

int main() {
    test(25);
    return 0;
}
