#include<stdio.h>

int main() {
    int arr[] = {1,2,2,2,3,1,3,5,5,1};
    int i,n,counter[10] = {0};
    n = sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<n;i++) {
        counter[arr[i]]++;
    }
    printf("Numbers that occur only two times are: ");
    for(i=0;i<n;i++) {
        if(counter[i]==2) {
            printf("%d ",i);
        }
    }

    return 0;
}
