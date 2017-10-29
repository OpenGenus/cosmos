#include<stdio.h>
int main()
{
	int num, i = 0;
	printf("Enter number to be reversed: \n");
	scanf("%d", &num);
	
	printf("Reverse of number %d is: ", num);
	while(num > 0) {
		printf("%d", num % 10);
		num = num / 10;
	}
	return 0;
}
