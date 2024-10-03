/* Following algorithm sorts the input array in ascending order
 * Time Complexity : O(n)-> Avg case and O(n^2)-> Worst Case
 */
#include <stdio.h>
#include <stdlib.h>

struct bucket {
	int count;
	float* value;
};

int comparator(const void* first, const void* second) {
	float a = *((int*)first), b = *((int*)second);
	int result = a - b;
	return (0 < result) - (result < 0);
}

void bucket_sort(float array[], int n) {
	struct bucket buckets[n];
	int a, b, c;
	for (a = 0; a < n; a++) {
		buckets[a].count = 0;
		buckets[a].value = malloc(sizeof(int) * n);
	}
	for (a = 0; a < n; a++) {
		int bi;
		bi = n * array[a];
		buckets[bi].value[buckets[bi].count++] = array[a];
	}
	for (c = 0, a = 0; a < n; a++) {
		qsort(buckets[a].value, buckets[a].count, sizeof(int), &comparator);
		for (b = 0; b < buckets[a].count; b++) {
			array[c + b] = buckets[a].value[b];
		}
		c += buckets[a].count;
		free(buckets[a].value);
	}
}

int main() {
	float array[100];
	int n = 100;
	int j, k;
	for (k = 0; k < n; k++) {
		array[k] = (double)(rand() % 1000) / 1000;
	}
	bucket_sort(array, n);
	for (j = 0; j < n; j++) {
		printf("%f ", array[j]);
	}
	printf("\n");
	return 0;
}
