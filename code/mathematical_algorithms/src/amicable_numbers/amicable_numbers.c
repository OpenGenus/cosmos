#include <stdio.h>

int
main()
{
  printf("Amicable Numbers below 10000 are:- \n");
  int m, i, j;
  for (m = 1; m <= 10000; m++) {
    int x = m;
    int sum1 = 0, sum2 = 0;
    for (i = 1; i < x; i++)
        if (x % i == 0)
            sum1 += i;

    int y = sum1;
    for (j = 1; j < y; j++)
        if (y % j == 0)
            sum2 += j;

    if (sum2 == x && x != y)
        printf("%d \n", x);
  }

  return (0);
}