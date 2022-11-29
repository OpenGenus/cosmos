#include<stdio.h>
#include<stdlib.h>
int 
merge(int a[],int l,int m,int h){
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
int 
mergesort(int a[],int l,int h){
    int n;
   
    if(h>l){
    n=(l+h)/2;
    mergesort(a,l,n);
    mergesort(a,n+1,h);
    merge(a,l,n,h);}}
int main(){
    int n;
    printf("Enter number of elements in an array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);   
    printf("\n");
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
    return (0);
}