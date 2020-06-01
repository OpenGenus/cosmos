    #include <stdio.h>
    #include <stdlib.h>
    /*
    Input : integer array indexed from 0, key to be searched
    Ouput : Position of the key in the array if found, else -1
    */
    int linearSearch(int a[], int n, int key) {
    int pos = -1;
    counter=0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == key) {
        pos = i;
        break;
        }
    }
    return pos;
    }

    int main() {
    int a[] = {8, 12, 3, 4, 7, 2, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int pos = linearSearch(a, n, 13);
    if (pos != 1)
        printf("Key found at position : %d \n", pos);
    else
        printf("Key not found \n");
    return 0;
    }

    /*
    Output :
    Key found at position : 2
    */
