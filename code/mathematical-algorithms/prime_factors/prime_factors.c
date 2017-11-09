#include <stdio.h>
int main()
{
	int num , isPrime;
	printf("Enter the number whose factors you want to know : ");
	scanf("%d",&num);
	int factor;
	printf("Factors of %d are \n",num);
	while(num>1)
	{
		for(int i=2; i<=num; i++)
	    {
	        if(num%i==0)
	        {
	            isPrime = 1;
	            for(int j=2; j<=i/2; j++)
	            {
	                if(i%j==0)
	                {
	                    isPrime = 0;
	                    break;
	                }
	            }
	            if(isPrime==1)
	            {
	                printf("%d ", i);
	                num = num / i;
	            }
	        }
	    }
	}
	
	return 0;
}
