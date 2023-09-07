#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Part of Cosmos by OpenGenus Foundation
void printSpiral(int N, int M, int[][M]);
void print(int N, int M, int[][M]);

int main()
{
	srand(time(NULL));
	const int N = 5;
	const int M = 5;
	int matrix[N][M]; 		// if you change N & M values, use malloc()
	int i, j;

	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			matrix[i][j] = rand()%100;		//I'm filling the matrix with random numbers

	print(N, M, matrix);
	printf("\n");
	printSpiral(N, M, matrix);

}

/*
*	Direction values:
*	0: from left to right
*	1: from top to bottom
*	2: from right to left
*	3: from bottom to top
*/

void print(int N, int M, int matrix[][M])
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
		
}

void printSpiral(int N, int M, int matrix[][M])
{
	int top = 0, bottom = N-1, left = 0, right = M-1;
	int direction = 0;	
	int i;

	while(top <= bottom && left <= right)
	{
		//printf("\ndir: %d\n", direction);
		switch(direction)
		{
			case 0:
				for(i = left; i <= right; i++)
					printf("%d ", matrix[top][i]);
				top++;
				break;
			case 1:
				for(i = top; i <= bottom; i++)
					printf("%d ", matrix[i][right]);
				right--;
				break;
			case 2:
				for(i = right; i >= left; i--)
					printf("%d ", matrix[bottom][i]);
				bottom--;
				break;
			case 3:
				for(i = bottom; i >= top; i--)
					printf("%d ", matrix[i][left]);
				left++;
				break;
		}

		direction = (direction + 1) % 4;	//if direction equals 3 it becomes 0, it increases by one otherwise
	}
	printf("\n");		
}
