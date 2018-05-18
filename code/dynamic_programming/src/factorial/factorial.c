#include <stdio.h>
int main()
{
	int number;
	printf("Enter a Whole Number: ");
	scanf("%d",&number);
    	int result[100001]={0};
   	result[0]=1;
  	for(int i=1;i<=number;i++)
        	result[i]=i*result[i-1];
	printf("%d! = %d\n", number, result[number]);
	return (0);
}
