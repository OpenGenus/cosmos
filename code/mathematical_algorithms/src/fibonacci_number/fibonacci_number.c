#include <stdio.h>

int 
main()
{
  int n, num1 = 0, num2 = 1, temp;

  printf("How many Fibonacci numbers do you want?\n");
  scanf("%d", &n);

  for (int i = 0; i <= n; i++) {
    printf("%d\n", num1);

    temp = num1 + num2;
    num1 = num2;
    num2 = temp;
  }
  return (0);
}
