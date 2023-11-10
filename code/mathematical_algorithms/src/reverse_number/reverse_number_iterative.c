
#include <stdio.h>;

/* iterative function to reverse digits of num*/
int reversDigits(int num)
{
    int rev_num = 0;
    while (num != 0)
    {
        rev_num = (rev_num)*10 + num % 10;
        num /= 10;
    }
    return rev_num;
}

/*Driver program to test reversDigits*/
int main()
{
    int num;
    printf("Enter the number\n");
    scanf("%d", &num);
    printf("Reverse of no. is %d", reversDigits(num));
    getchar();
    return 0;
}
