#include <stdio.h>
int i, v, num1 = 0, num2 = 1, temp;

int main() {
  // Enter here number of times fib number is calculated;
  scanf("%d", &v);
  printf("Fibonacci numbers:");
  
  for (i; i <= v; i++) {
    // This prints fibonacci number;
    printf("%d, ", num1);
    // This calculates fibonacci number;
    temp = num1 + num2;
    num1 = num2;
    num2 = temp;
  }
  return 0;
}
