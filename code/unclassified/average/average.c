#include<stdio.h>

int average(int arr[],int n) {
    int i,sum=0;
    for(i=0;i<n;i++) {
        sum += arr[i];
    }
    int result = sum/n;

return result;
}

int main() {

int arr[] = {1,2,3,4,5};
int n = sizeof(arr)/sizeof(arr[0]);
int result = average(arr,n);
printf("average is %d",result);

return 0;
}
