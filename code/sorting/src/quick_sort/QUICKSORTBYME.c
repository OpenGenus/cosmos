#include<stdio.h>
#include<stdbool.h>
#include<time.h>
int partition(int a[],int l,int h){
    int i,j,pivot;
    i=l-1;
    j=h+1;
    pivot=a[l];
    while(true){
        do{
            j--;
        }while(a[j]>pivot);

        do{
            i++;
        }while(a[i]<pivot);

        if(i<j){
            int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }else{
            return j;
        }
    }
}
void quicksort(int a[],int p,int r){
    int q;
    if(p<r){
        q=partition(a,p,r);
        quicksort(a,p,q);
        quicksort(a,q+1,r);
    }
}
int main(){
    double timespent=0.0;
    clock_t start=clock();
    int arr[2000];
    for(int i=0;i<2000;i++){
     arr[i]   = rand();
    }
    int n = sizeof(arr) / sizeof(int);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    timespent += (double)(end - start) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds", timespent);

}