#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

int 
min(int x, int y, int z)
{
   if (x < y)
      return ((x < z)? x : z);
   else
      return ((y < z)? y : z);
}
 
int 
minCost(int cost[ROWS][COLUMNS], int m, int n)
{
     int i, j;
     int travellingCost[ROWS][COLUMNS];  
 
     travellingCost[0][0] = cost[0][0];
 
     for (i = 1; i <= m; i++)
        travellingCost[i][0] = travellingCost[i - 1][0] + cost[i][0];
 
     for (j = 1; j <= n; j++)
        travellingCost[0][j] = travellingCost[0][j - 1] + cost[0][j];
 
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            travellingCost[i][j] = min(travellingCost[i - 1][j - 1], travellingCost[i - 1][j], travellingCost[i][j - 1]) + cost[i][j];
 
     return (travellingCost[m][n]);
}

int 
main()
{
   int cost[ROWS][COLUMNS] = { {1, 2, 3}, {4, 8, 2}, {1, 5, 3} };
   printf("%d \n", minCost(cost, 2, 2));

   return (0);
}
