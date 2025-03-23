#include<stdio.h>
#include<math.h>

int abs(int x){
    return sqrt(x*x);
}

int main(){
    int num,sumdig=0;
    scanf("%d",&num);
    while(num>9 || num<-9){
        sumdig+=abs(num%10);
        num=num/10;
    }
    sumdig+=abs(num);
    printf("%d",sumdig);
}
