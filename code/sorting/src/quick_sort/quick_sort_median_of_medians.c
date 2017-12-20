#include<stdio.h>
#define SIZE 10000

int a[SIZE], b[SIZE];
int count = 0;

void swap(int *a,int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int median(int x, int y, int z)
{
	if((x > y && x < z) || (x > z && x < y)) return 1;
	else if((y > x && y < z) || (y < x && y > z)) return 2;
	else return 3;
}

void qsort(int l, int r)
{
	if(l >= r)
	return;
	
	count += (r - l);
	
	int pvt, i, j, temp;
	temp = median(a[l], a[(r + l) / 2], a[r]);

	switch(temp)
	{
	case 1: break;
	case 2: swap(&a[l], &a[(r+l)/2]); break;
	case 3: swap(&a[l], &a[r]);
	}
	pvt = a[l];

	for(i = l + 1, j = l + 1; j <= r; j++)
	if(a[j] < pvt)
	{
		temp = a[j]; a[j] = a[i]; a[i] = temp; i++;
	}

	temp = a[l]; a[l] = a[i - 1]; a[i - 1] = temp;

	qsort(l, i - 2);
	qsort(i, r);
}

int main()
{
	int i;
	for(i = 0; i < SIZE; i++)
	scanf("%d", a + i);

	qsort(0, SIZE - 1);

	printf("\n%d\n", count);
	
	return 0;
}
