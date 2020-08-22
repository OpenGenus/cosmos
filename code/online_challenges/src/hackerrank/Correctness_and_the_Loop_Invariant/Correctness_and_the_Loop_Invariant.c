#include <stdio.h>
void insertionSort(int N, int arr[]) {
    int i,d,temp;
    int value;
    for(i=1;i<N;i++)
    {   d=i;
        while(d>0 && arr[d]<arr[d-1])
        {
        temp=arr[d];
        arr[d]=arr[d-1];
        arr[d-1]=temp;
        d--;
        }
    }
    for(i=0;i<N;i++)
    {
        printf("%d",arr[i]);
        printf(" ");
    }
}

int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}
