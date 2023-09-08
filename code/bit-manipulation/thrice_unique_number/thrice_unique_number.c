#include<stdio.h>

int main() {
    int arr[] = {1,2,2,2,3,1,1};
    int i,n,counter[7] = {0};
    n = sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<n;i++) {
        counter[arr[i]]++;
    }
    for(i=0;i<n;i++) {
        if(counter[i]==1) {
            printf("%d",i);
        }
    }

    return 0;
}
