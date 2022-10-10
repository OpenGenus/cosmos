#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int 
partition(int a[],int l,int h){
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
            return (j);
        }
    }
}
void 
quicksort(int a[],int p,int r){
    int q;
    if(p<r){
        q=partition(a,p,r);
        quicksort(a,p,q);
        quicksort(a,q+1,r);
    }
}
int main(){
    int n;
    printf("Enter number of elements in an array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int d=rand()%n;
    int temp;
    temp=a[0];
    a[0]=a[d];
    a[d]=temp;
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }

}