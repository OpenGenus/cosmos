Okay let me try to explain the thought process behind this code.
Prerequisite: number of inversions {A[i] > A[j] : i < j} can be counted during the merge step of merge sort.

So we start with the standard merge code in mergesort:

```
  public void merge(int[] A, int l, int m, int r, int[] M) {
	int i = l, j = m + 1, k = 0;
	while(i <= m && j <= r) {
		M[k++] = A[i] <= A[j] : A[i++] : A[j++];
	}
	while(i <= m) {
		M[k++] = A[i++];
	}
	while(j <= r) {
		M[k++] = A[j++];
	}
	for(i = l; i <= r; i++) {
		A[i] = M[i - l];
	}
}

```
We can achieve the same goal by tweaking the first while loop into a for loop like this (this makes the inversions counting part cleaner as we'll see in a sec):
```
public void merge(int[] A, int l, int m, int r, int[] M) {
	int i = l, k = 0;
	for(int j = m + 1; j <= r; j++) {
		while(i <= m && A[i] <= A[j]) {
			M[k++] = A[i++];
		}
		M[k++] = A[j];
	}
	while(i <= m) {
		M[k++] = A[i++];
	}
	for(i = l; i <= r; i++) {
		A[i] = M[i - l];
	}
}
```
