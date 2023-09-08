#include<stdio.h>
// Part of Cosmos by OpenGenus Foundation
int gcd(int x, int y){
    while(x!=y){
        if(x>y) x-=y;
        else y-=x;
    }
    return x;
}

int lcm(int x, int y){
    return x*y/gcd(x,y);
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("GCD = %d\n",gcd(a,b));
    printf("LCM = %d",lcm(a,b));
}
