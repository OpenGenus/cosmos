#includen<stdio.h> 
#include<conio.h> 

int hcf(int a, int h) 
{
    int temp; 
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
} 

int main() 
{
    int c,d,gcd; 
    printf("enter two values to find for relative prime or co prime\n");
    scanf("%d%d",&c,&d);
    gcd=hcf(c,d);
   
    if(gcd==1) 
    {
        printf("\n%d and %d are relatively prime or co prime numbers .",c,d);
    }
    else
    {
        printf("\n%d and %d are not relatively prime or co prime numbers .",c,d);
    }         
    getch(); 
}
