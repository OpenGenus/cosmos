#include<stdio.h>

int factorial_recursive(int n){
    if(n==0) return 1;
    else return n*factorial_recursive(n-1);
}

int factorial_iteration(int n){
    int res=1;
    while(n){
        res = res*n;
        n--;
    }
    return res;
}

int main(){
    int n;
    printf("\nEnter a number - ");
    scanf("%d",&n);
    printf("Result using recursion - %d",factorial_recursive(n));
    printf("\nResult using iteration - %d",factorial_iteration(n));
}