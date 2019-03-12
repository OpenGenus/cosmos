#include<stdio.h>

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);
int
main()
{
    int n;
    char source,destination,auxi;
    printf("Enter no. of disk:");
    scanf("%d",&n);
    printf("Enter source rod name:");
    scanf(" %c",&source);
    printf("Enter Destination rod name:");
    scanf(" %c",&destination);
    printf("Enter Auxi. rod name:");
    scanf(" %c",&auxi);
    TowerOfHanoi(n,source ,destination,auxi);
	return 0;
}

void
TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 1) {
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
		return ;
	}
	TowerOfHanoi(n-1, from_rod, aux_rod, to_rod);
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	TowerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
