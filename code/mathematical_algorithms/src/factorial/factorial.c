#include<stdio.h>
 
// function to find factorial of given number
unsigned int 
factorial(unsigned int n)
{
    if (n == 0)
		return (1);

    return (n * factorial(n - 1));
}
 
int 
main()
{
    int num = 5;
    printf("Factorial of %d is %d", num, factorial(num));
    return (0);
}
