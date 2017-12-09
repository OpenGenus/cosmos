#include <stdio.h>

int main()
{
    int n,i;
    int a=0,b=1,c=2,d;
    printf("Enter a Number\n");
    scanf("%d",&n);
    printf("%d %d %d ",a,b,c);
    for(i=0;i<n-3;i++){
        d = a + b + c;
        printf("%d ",d);
        a = b;
        b = c;
        c = d;
    }

  return (0);
}