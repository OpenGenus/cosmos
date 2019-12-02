#include<stdio.h>
#include "mymath.h"

int main() {
	int a, b;
	printf("Hello World\n\n");

	printf("Enter Two Numbers(A B): ");
	scanf("%d %d", &a, &b);

	printf("Addition: %d\n", add(a, b));
	printf("Subtraction: %d\n", subtract(a, b));
	printf("Multiplication: %d\n", multiply(a, b));
	printf("Division: %d\n\n", divide(a, b));

	return 0;
}
