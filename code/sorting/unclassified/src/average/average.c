// Part of Cosmos by OpenGenus Foundation
// Code written by Adeen Shukla (adeen-s)
#include <stdio.h>

int 
main() 
{
    int n, tmp = 0, i;
    double sum = 0.0;
    
    printf("Enter the total number of inputs : ");
    scanf("%d", &n);
    printf("\nEnter the numbers\n");
    
    for (i = 0; i < n; i++, sum += tmp) {
	   scanf("%d", &tmp);		
    }

    printf("\nAverage = %2.2f\n", (sum / n));

    return (0);
}
