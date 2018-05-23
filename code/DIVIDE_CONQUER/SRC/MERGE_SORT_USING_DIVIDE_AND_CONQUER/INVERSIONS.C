#include <stdio.h>

const int maxn = 1e6;
typedef long long unsigned llu;

llu merge(int v[], int lo, int mid, int hi) {
	llu inv = 0;
	int i, j, k;
	int n1 = mid - lo  + 1, n2 = hi - mid;
	int left[n1], right[n2];
	for(i = 0; i < n1; i++) left[i] = v[i+lo];
	for(j = 0; j < n2; j++) right[j] = v[j+mid+1];

	i = 0, j = 0, k = lo;

	while(i < n1 && j < n2) {
		if(left[i] >= right[j]) {
			v[k] = left[i];
			i++;
			inv += j;
		} else {
			v[k] = right[j];
			j++;
			inv++;
		}
		++k;
	}
	inv -= j;
	while(i < n1) {
		v[k] = left[i];
		++k; ++i;
		inv += j;
	}
	while(j < n2) {
		v[k] = right[j];
		++k; ++j;
	}
	return inv;
}

llu mergeSort(int v[], int lo, int hi) {
	llu inv = 0;
	if(lo < hi) {
		int mid = (lo+hi)/2;
		inv += mergeSort(v, lo, mid);
		inv += mergeSort(v, mid+1, hi);
		inv += merge(v, lo, mid, hi);
	}
	return inv;
}

llu inversions(int v[], int lo, int hi) {
	int size = hi-lo+1, u[size];
	for(int i = 0; i < size; i++) {
		u[i] = v[i+lo];
	}
	return mergeSort(u, 0, size-1);
}

int main() {
	int n, v[maxn];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	printf("Inversions: %llu\n", inversions(v, 0, n-1));
	return 0;
}
