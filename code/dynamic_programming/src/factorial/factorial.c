#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int number;
	printf("Enter a Whole Number: ");
	scanf("%d",&number);
    int *result=(int*)malloc(number*(sizeof(int)));
    memset(result,0,sizeof(int)*number);
   	result[0]=1;
  	for(int i=1;i<=number;i++)
        	result[i]=i*result[i-1];
	printf("%d! = %d\n", number, result[number]);
	free(result);
	return (0);
}
