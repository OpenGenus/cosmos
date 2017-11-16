#include <stdio.h>

int main()

{
  printf("Enter the number of Disks");
  int n;
  scanf("%d", &n);
  for (int i = 1; i < (1 << n); i++)
    printf("\nMove from Peg %d to Peg %d", (i & i - 1) % 3 + 1,
           ((i | i - 1) + 1) % 3 + 1);
  return 0;
}
