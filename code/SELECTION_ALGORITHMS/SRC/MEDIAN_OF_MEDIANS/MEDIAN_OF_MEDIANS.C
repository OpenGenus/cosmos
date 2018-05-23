// Part of OpenGenus/cosmos
// Author : ABDOUS Kamel

// The median of medians algorithm.
// Deterministic select algorithm that executes
// in O(n) in the worst case.

#include <stdio.h>

#define MEDIAN_GROUPS_SIZE 5

int partition(int array[], int beg, int end, int pivotIndex)
{
	int pivotValue = array[pivotIndex];

	array[pivotIndex] = array[end];
	array[end] = pivotValue;

	int i, swapVar, curIndex = beg;

	for(i = beg; i < end; ++i)
	{
		if(array[i] < pivotValue)
		{
			swapVar = array[curIndex];
			array[curIndex] = array[i];
			array[i] = swapVar;

			curIndex++;
		}
	}

	array[end] = array[curIndex];
	array[curIndex] = pivotValue;

	return curIndex;
}

void insertionSort(int array[], int beg, int end)
{
	int i, j, key;

	for(i = beg + 1; i <= end; ++i)
	{
		key = array[i];

		j = i - 1;
		while(j >= beg && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}

		array[j + 1] = key;
	}
}

// Returns the median of medians.
int getMedianOfMedians(int array[], int beg, int end)
{
	int arraySize = end - beg + 1;

	if(arraySize <= MEDIAN_GROUPS_SIZE)
		return beg + (arraySize / 2);

	int i = beg, 
		medGroupsEnd = beg,
		medianPos, j, swapVar;

	// Store in the beginning of the array the medians of medians (array[beg..medGroupsEnd]).
	while(i <= end)
	{
		j = i + MEDIAN_GROUPS_SIZE - 1;
		if(j > end)
			j = end;

		insertionSort(array, i, j);

		medianPos = i + (j - i + 1) / 2;

		swapVar = array[medGroupsEnd];
		array[medGroupsEnd] = array[medianPos];
		array[medianPos] = swapVar;

		medGroupsEnd++;
		i = j + 1;
	}

	return getMedianOfMedians(array, beg, medGroupsEnd);
}

// Returns the k-th smallest element in array[beg..end]
int selectKth(int array[], int beg, int end, int k)
{
	if(end <= beg)
		return beg;

	int pivotIndex = partition(array, beg, end, getMedianOfMedians(array, beg, end));

	if(pivotIndex == k - 1)
		return pivotIndex;

	else if(pivotIndex < k - 1)
		return selectKth(array, pivotIndex + 1, end, k);

	else 
		return selectKth(array, beg, pivotIndex - 1, k);
}

int main()
{
	int a[] = {98, 65, 12, 365, 7, 8, 9, 12, 65};

	int i;
	for(i = 0; i < 8; ++i)
	{
		printf("%d\n", a[selectKth(a, 0, 8, i + 1)]);
	}

	return 0;
}
