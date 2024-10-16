#include<stdio.h>

int main(){
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    int digit_count=0;
    for(int i=n;i>0;i/=10){
        digit_count++;
    }
    int square_of_n=n*n;
    //digit extraction from behind in square
    int digits=0;
    int power=0;
    for(int i=square_of_n;i>0;i/=10){
        if(power+1<=digit_count){
        digits+=(i%10)*pow(10,power);
        power++;
        }
    }
    if(digits==n){
        printf("\n%d is automorphic\n",n);
    }
    else{
        printf("%d is not automorphic\n",n);
    }
}