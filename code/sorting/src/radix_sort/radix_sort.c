#include <stdio.h>
#include <stdlib.h>
// Part of Cosmos by OpenGenus Foundation
// Initial code by GelaniNijraj
// Debug by adeen-s
int find_max(int* number, int length){
	int i, max = number[0];
	for(i = 0; i < length; i++)
		max = number[i] > max ? number[i] : max;
	return max;
}

int* sort(int* number, int length){
	int i, j;
	int k = 0, n = 1, max, lsd;
	int** temp = (int **)malloc(sizeof(int) * length);
	int* order;

	max = find_max(number, length);
	for(i = 0; i < length; i++)
		temp[i] = (int *)calloc(length, sizeof(int));
	order = (int *)calloc(length, sizeof(int));
	while(n <= max){
		for(i = 0; i < length; i++){
			lsd = (number[i] / n) % 10;
			temp[lsd][order[lsd]] = number[i];
			order[lsd] += 1;
		}
		for(i = 0; i < length; i++){
			if(order[i] != 0){
				for(j = 0; j < order[i]; j++){
					number[k] = temp[i][j];
					k += 1;
				}
			}
			order[i] = 0;
		}
		n *= 10;
		k = 0;
	}
	return number;
}

void display(int* number, int length){
	int i;
	for(i = 0; i < length; i++)
		printf("%d ", number[i]);
	printf("\n");
}

int main(int argc, char** argv){
	int arr[] = {34,3212,51,52,612,456,12,31,412,123,1,3};
	int length = 12;
	printf("Before : ");
	display(arr, length);
	sort(arr, length);
	printf("After : ");
	display(arr, length);
	return 0;
}
