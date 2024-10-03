#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))

const int RUN = 32;


/*InsertionSort*/
void
insertionSort(int *A , int left, int right)
{

    int i, j;
    for (i = left + 1; i <= right; i++) {
        int temp = A[i];
        int j = i - 1;
        while (A[j] > temp && j >= left) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

/*Merge*/
void
merge(int *A, int p, int q, int r)
{

    int i, j;
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L1 = malloc((n1 + 1) * sizeof(int));
    int *L2 = malloc((n2 + 1) * sizeof(int));

    for(i = 0; i < n1; i++)
        L1[i] = A[p + i];
    for(j = 0; j < n2; j++)
        L2[j] = A[q + j + 1];

    L1[n1] = INT_MAX;
    L2[n2] = INT_MAX;

    i = j = 0;

    int k;
    for(k = p; k <= r; k++) {
        if(L1[i] <= L2[j]) {
            A[k] = L1[i];
            i++;
        }
        else {
            A[k] = L2[j];
            j++;
        }
    }

    free(L1);
    free(L2);
}

/*TimSort*/
void
timSort(int *A, int len)
{

    int i;
    for(i = 0; i < len; i += RUN) {
        insertionSort(A, i, min((i + 31), (len - 1)));
    }


    int size, left, right, mid;
    for(size = RUN; size < tamanho; size *= 2){
        for(left = 0; left < tamanho; left += 2 * size){
            mid = left + size - 1;
            right = min((left + 2 * size - 1), (tamanho - 1));

            merge(A, left, mid, right);
        }
    }
}

int
main()
{

    int A[5];

    for(int i; i < 5; i++) {
      scanf("%d", &A[i]);
    }

    timSort(A, 5);
    int i;
    for(i = 0;i < 5; i++) {
      printf("-%d-", A[i]);
    }
}
