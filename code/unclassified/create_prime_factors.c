#include<stdio.h>

int isPrime(int n) {
    int i,flag=1;
    for(i=2;i<n;i++) {
        if(n%i==0) {
            flag=0;
            return -1;
        }else {
            flag=1;
        }
    }
    if(flag==1) {
        return 1;
    }
}


void printPrimeFactors(int n) {
    int i,res=n;
    for(i=2;i<n;i++) {
        if(res%i==0 && isPrime(i)==1) {
            res = n/i;
            printf("%d ",i);
        }
    }
}


int main() {

int n,i;
printf("Enter a number to check its prime factors\n");
scanf("%d",&n);
printPrimeFactors(n);



return 0;
}
