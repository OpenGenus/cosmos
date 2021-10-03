#include <stdio.h>

int main(){
    int m;
    printf("Enter the number of elements in first array\n");
    scanf("%d",&m);
    int arr1[m];
    int n;
    printf("\nEnter the number of elements in second array\n");
    scanf("%d",&n);
    int arr2[n];
    printf("\nEnter the elements of first array\n");
    for(int i=0;i<m;i++){
        scanf("%d",&arr1[i]);
    }
    printf("\nEnter the elements of second array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    int arr[m+n];
    int i=0;
    for(i=0;i<m;i++){
        arr[i]=arr1[i];
    }
    for(int j=0;j<n;j++){
        arr[i+j]=arr2[j];
    }
    printf("\nFirst array is\n");
    for(int i=0;i<m;i++){
        printf("%d ",arr1[i]);
    }
    printf("\nSecond array is\n");   
        for(int i=0;i<n;i++){
        printf("%d ",arr2[i]);
    }
    printf("\nMerged array is\n");
    for(int i=0;i<m+n;i++){
        printf("%d ",arr[i]);
    }
}
