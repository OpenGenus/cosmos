#include <stdio.h>

#define INT_MIN -32767 
#define max(a, b) (((a) > (b)) ? (a) : (b))
 
int 
cutRod(int price[], int length_of_rod)
{
   if (length_of_rod <= 0)
     return (0);

   int max_val = INT_MIN, i;
   for (i = 0; i < length_of_rod; i++)
         max_val = max(max_val, price[i] + cutRod(price, length_of_rod - i - 1));
 
   return (max_val);
}

int 
main()
{
    int length_of_rod;
    printf("Enter length of rod: ");
    scanf("%d", &length_of_rod);

    int price[length_of_rod], i;
    printf("Enter prices: \n");
    for (i = 0; i < length_of_rod; i++)
      scanf("%d", &price[i]);

    printf("Maximum Obtainable Value is %d \n", cutRod(price, length_of_rod));

    return (0);
}
