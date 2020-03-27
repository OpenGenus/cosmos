// MAXDIFF in C - CodeChef 

#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        int k,n;
        scanf("%d %d",&n,&k);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);}
        int min;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>=arr[j]){
                    min=arr[i];
                    arr[i]=arr[j];
                    arr[j]=min;
                }}}
        int c;
        c=n/2;
        if(k<=c){   
            int sum=0;
            for(int i=0;i<k;i++){
                sum=sum+arr[i];}
            int sum1=0;
            for(int i=k;i<n;i++){
                sum1=sum1+arr[i];}
    
            int a;
            a=sum1-sum;
            printf("\n%d",a);
        }
        else {
            int sum2=0;
            int sum3=0;
            for(int i=0;i<n-k;i++){
                sum2=sum2+arr[i]; }
            for(int i=n-k;i<n;i++) {
                sum3=sum3+arr[i];}
            int b;
            b=sum3-sum2;
            printf("\n%d",b);
        }}
    return 0;
}