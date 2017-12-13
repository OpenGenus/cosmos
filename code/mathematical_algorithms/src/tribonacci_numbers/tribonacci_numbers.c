#include <stdio.h>

int
main()
{
    int n;
    int a = 0,b = 1,c = 2,d;
    printf("Enter a Number\n");
    scanf("%d",&n);
    printf("%d %d %d ",a,b,c);
    for (int i = 0; i < n-3; i++) {
        d = a + b + c;
        printf("%d ",d);
        a = b;
        b = c;
        c = d;
    }

  return (0);
}