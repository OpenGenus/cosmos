#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
#define MAX 10
#define MAXIMUM(a, b) a > b ? a : b

void 
Knapsack(int no, int wt, int pt[MAX], int weight[MAX])
{
	int knap[MAX][MAX], x[MAX] = {0};

	int i, j;
    //For item
    for (i = 0; i <=no; i++)
        knap[i][0] = 0;
    //For weight
    for (i = 0; i <=wt; i++)
        knap[0][i] = 0;

	for (i = 1; i <= no; i++)
		for (j = 1; j <= wt; j++) {
			if ((j - weight[i]) < 0)
				knap[i][j] = knap[i - 1][j];
			else
				knap[i][j] = MAXIMUM(knap[i - 1][j], pt[i] + knap[i - 1][j - weight[i]]);
		}

	printf("Max Profit : %d \n", knap[no][wt]);
	printf("Edges are :\n");
	for (i = no; i >= 1; i--)
		if (knap[i][wt] != knap[i-1][wt]) {
			x[i] = 1;
			wt -= weight[i];
		}

	for (i = 1; i <= no; i++)
		printf("%d\t", x[i]);
	printf ("\n");
	
}

int 
main(int argc, char *argv[])
{
	int no, wt, pt[MAX] = {0}, weight[MAX] = {0};
	int i;

	printf("Enter the no of objects :\n");
	scanf("%d", &no);

	printf("Enter the total weight :\n");
	scanf("%d", &wt);

	printf("Enter the weights\n");
	for (i = 1; i <= no; i ++)
		scanf("%d", &weight[i]);

	printf("Enter the profits\n");
	for (i = 1; i <= no; i ++)
		scanf("%d", &pt[i]);

	Knapsack(no, wt, pt, weight);
	return (0);
}
