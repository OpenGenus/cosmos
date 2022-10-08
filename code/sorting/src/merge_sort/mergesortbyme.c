#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int merge(int a[],int l,int m,int h){
    int b[100],i,j,k;
    i=l,j=m+1,k=l;
    while(i<=m && j<=h){
        if(a[i]<a[j]){
            b[k]=a[i];
            k++;
            i++;
        }else{
            b[k]=a[j];
            k++;
            j++;
        }
    }
    if(i>m){
        while(j<=h){
            b[k++]=a[j++];
        }}
    else{
            while(i<=m){
            b[k++]=a[i++];
        }}
    for(int q=l;q<=h;q++){
        a[q]=b[q];
    }
    
}
int mergesort(int a[],int l,int h){
    int n;
   
    if(h>l){
    n=(l+h)/2;
    mergesort(a,l,n);
    mergesort(a,n+1,h);
    merge(a,l,n,h);}}
int main(){
    double timespent=0.0;
    clock_t start=clock();
int arr[] ={1,3,2,5,};
    int n = sizeof(arr) / sizeof(int);
mergesort(arr,0,n-1);   
printf("\n");
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    timespent += (double)(end - start) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds", timespent);}