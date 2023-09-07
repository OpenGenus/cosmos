#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printarr(int arr[],int n)
{
    for(int i = 0;i < n;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}




int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int num1,num2,x = 0;
        int matcharr[] = {6,2,5,5,4,5,6,3,7,6};
        int c[100000];
        int sum_matches = 0;
        int sum = 0;
        scanf("%d%d",&num1,&num2);
        sum = num1 + num2;
        while(sum != 0)
        {
            int temp = sum%10;
            c[x++] = temp;
            sum = sum/10;
        }
        for(int i = 0;i < x;++i)
        {
            sum_matches += matcharr[c[i]];
        }
        printf("%d\n",sum_matches);
    }
    return 0;
}
