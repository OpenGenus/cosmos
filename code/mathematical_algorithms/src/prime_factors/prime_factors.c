#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
int main()
{
    int num;
    bool isPrime;
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
                isPrime = true;
                for(int j=2; j<=i/2; j++)
                {
                    if(i%j==0)
                    {
                        isPrime = false;
                        break;
                    }
                }
                if(isPrime==true)
                {
                    printf("%d ", i);
                    num /= i;
                }
            }
        }
    }
    printf("\n");
    return 0;
}
