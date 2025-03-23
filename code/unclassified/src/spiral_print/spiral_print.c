#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Part of Cosmos by OpenGenus Foundation
void printSpiral(int N, int M, int ** mat);
void print(int N, int M, int ** mat);

/*
	Creates a matrix on the heap (uses malloc).
	And initializes the matrix with random numbers. 
*/
int ** createMatrix(int N, int M);

/*
	Destroys the matrix and tidy up. 
*/
void freeMatrix(int N, int M, int ** matrix);

int main()
{
	const int N = 5;
	const int M = 5;
	int ** matrix = createMatrix(N,M); // ueses the heap
	int i, j;	

	print(N, M, matrix);
	printf("\n");
	printSpiral(N, M, matrix);

	freeMatrix(N, M, matrix); // tidy up 

}

/*
*	Direction values:
*	0: from left to right
*	1: from top to bottom
*	2: from right to left
*	3: from bottom to top
*/

void print(int N, int M, int ** matrix)
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
		
}

void printSpiral(int N, int M, int ** matrix)
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

		//if direction equals 3 it becomes 0, it increases by one otherwise
		direction = (direction + 1) % 4;	
	}
	printf("\n");		
}

int ** createMatrix(int N, int M) 
{
	int ** array = (int**) malloc(sizeof(int *) * N);
	int i,j;
	srand(time(NULL));
	for(i = 0; i < N; i++) 
	{
		array[i] = (int *) malloc(sizeof(int) * M);
		for(j = 0; j < M; j++)
			array[i][j] = random() % 100;
	}

	return array;

}

void freeMatrix(int N, int M, int ** matrix) 
{
	int i;
	for(i = 0; i < N; i++)
		free(matrix[i]);
	free(matrix);
	
}