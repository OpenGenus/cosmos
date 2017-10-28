#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isSorted(int *arr, int length);
void shuffle(int *arr, int count);
void sort(int *arr, int length);

int main(int argc, char* argv[]) {
    srand((unsigned) time( NULL));

    if (argc > 2) {
        int arr[(argc - 1)];

        for (int i = 1; i < argc; i++) {
            arr[i - 1] = atoi(argv[i]);
        }

        sort(arr, (argc - 1));

        printf("[ ");

        for (int i = 0; i < (argc - 2); i++) {
            printf("%i, ", arr[i]);
        }

        printf("%i ]\n", arr[argc - 2]);
    } else {
        printf("An array needs to be passed in!\n");
    }
}

int isSorted(int *arr, int length) {
    for (int i = 1; i < length; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }
    return 1;
};

void shuffle(int *arr, int count) {
    int temp, index;
    while (count > 0) {
        index = (int) (rand() % count);
        count--;
        temp = arr[count];
        arr[count] = arr[index];
        arr[index] = temp;
    }
}

void sort(int *arr, int length) {
    int sorted = 0;
    while (!sorted) {
        shuffle(arr, length);
        sorted = isSorted(arr, length);
    }
}
