#include <stdio.h>

int main()
{
    int n, i;
    float a[100], sum = 0.0, average;

    printf("Enter the numbers of elements: ");
    scanf("%d", &n);//here we are taking the number of elements we want in array//

    while (n > 100 || n <= 0)
    {
        printf("Error! number should in range of (1 to 100).\n");
        printf("Enter the number again: ");
        scanf("%d", &n);
    }

    for(i = 0; i < n; ++i)
    {
        printf("%d. Enter number: ", i+1);
        scanf("%f", &a[i]);
        sum += a
        [i];
    }

    average = sum / n;
    printf("Average = %.2f", average);

    return 0;
}
