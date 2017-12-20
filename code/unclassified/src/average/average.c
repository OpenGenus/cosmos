// Part of Cosmos by OpenGenus Foundation
// Code written by Adeen Shukla (adeen-s)
#include<stdio.h>

int main() {
	int n, sum = 0, tmp = 0, i;
    
    printf("Enter the total number of inputs : ");
    scanf("%d", &n);
	printf("\nEnter the numbers\n");
    
    for (i = 0; i < n; i++) {
	   scanf("%d", &tmp);
	   sum += tmp;		
    }

    float avg = (float) sum / n;
    printf("\nAverage = %f\n", avg);
}
