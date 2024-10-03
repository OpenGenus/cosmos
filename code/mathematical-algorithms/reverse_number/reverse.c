#include<stdio.h>
int main()
{
	int num, i = 0;
	printf("Enter number to be reversed: \n");
	scanf("%d", &num);
	
	printf("Reverse of number %d is: ", num);
	
	if(num < 0){
		printf("-");
		num = -1 * num;
	}
	if(num != 0){
    	while(num > 0) {
    		printf("%d", num % 10);
    		num = num / 10;
    	}
	}
	else
	    printf("0");
	return 0;
}
