#include<stdio.h>

int n,Max0=0,Max1=0,i;

int MaxSum(int X[], int Size){
    for( i=0;i<Size;i++){
        Max1+=X[i];
        if(Max0<Max1) Max0=Max1;
        if(Max1<0) Max1=0;
    }
    return Max0;
}

int main(){
    int a[4000];
        scanf("%d",&n);
        for( i=0;i<n;i++) scanf("%d",&a[i]);
        printf("%d",MaxSum(a,n));
}
