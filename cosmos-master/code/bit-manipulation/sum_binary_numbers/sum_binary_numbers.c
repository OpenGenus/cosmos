#include <stdio.h>
 
int main()
{
 
    long bin1, bin2;
    int i = 0, remainder = 0, sum[20];
 
    printf("Enter the first binary number: ");
    scanf("%ld", &bin1);
    printf("Enter the second binary number: ");
    scanf("%ld", &bin2);
    while (bin1 != 0 || bin2 != 0)
    {
        sum[i++] =(bin1 % 10 + bin2 % 10 + remainder) % 2;
        remainder =(bin1 % 10 + bin2 % 10 + remainder) / 2;
        bin1 = bin1 / 10;
        bin2 = bin2 / 10;
    }
    if (remainder != 0)
        sum[i++] = remainder;
    --i;
    printf("Sum of two binary numbers: ");
    while (i >= 0)
        printf("%d", sum[i--]);
    return 0;
}
