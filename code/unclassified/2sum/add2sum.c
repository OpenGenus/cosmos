#include<stdio.h>

int BinarySearch(int A[],int n,int x) {
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(x==A[mid]) {
            return mid;
        } else if(x < A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}


int main() {
    int arr[] = {5,3,2,6,7},target,i,remaining,second,flag=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter the target value from array\n");
    scanf("%d",&target);

    for(i=0;i<n;i++) {
        if(target>=arr[i]) {
            remaining = target - arr[i];
            second = BinarySearch(arr,n,remaining);
            if(second!=0) {
                printf("%d %d",i,second);
                flag=1;
                break;
            }
        }
    }
    if(flag!=1) {
        printf("Not possible\n");
    }

    return 0;
}
