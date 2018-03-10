// Part of Cosmos by OpenGenus Foundation

#include<stdio.h>

int 
hcf(int a, int h) 
{
    int temp; 
    while (1) {
        temp = a % h;
        if (temp == 0)
        	return h;
        a = h;
        h = temp;
    }
} 

int 
main() 
{
    int c, d, gcd; 
    printf("Enter two Natural Numbers\n");
    scanf("%d %d", &c, &d);
    gcd = hcf(c, d);
   
    if (gcd == 1) 
        printf("%d and %d are relatively prime or co prime numbers . \n", c, d);
    else
        printf("%d and %d are not relatively prime or co prime numbers . \n", c, d);

     return (0);     
}
