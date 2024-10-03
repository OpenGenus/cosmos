    #include <math.h>
    #include <stdio.h>
    int main()
    {
    int lower, upper, i, temp1, temp2, rem, num = 0;
    float sum_pow = 0.0;
    /* Accept the lower and upper range from the user */
    printf("Enter lower range: ");
    scanf("%d", &lower);
    printf("Enter upper range: ");
    scanf("%d", &upper);
    
    printf("Armstrong numbers between %d and %d are: ", lower, upper);

    for (i = lower ; i <= upper; ++i)
    {
        temp1 = i;
        temp2 = i;

        // calculate number of digits
        while (temp1 != 0)
        {
            temp1 /= 10;
            ++num;
        }
        // calculate sum of nth power of its digits
        while (temp2 != 0) {
            rem = temp2 % 10;
            sum_pow += pow(rem, num);
            temp2 /= 10;
        }

        // check if it is an Armstrong number
        if ((int)sum_pow == i) {
            printf("%d ", i);
        }

        num = 0;
        sum_pow = 0;
    }
    return 0;
    }
