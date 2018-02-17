#include <stdio.h>

int 
max(int const a, int const b, const int c)
{
	if (a > b)
		return (a > c ? a : c);

	return (b > c ? b : c);
}

int 
maximumContiguousSubsequenceSum(const int a[], int beg, int end)
{
	if (beg == end)
		return (a[beg] > 0 ? a[beg] : 0);

	int mid = (beg + end) / 2;
	int leftSubProblem = maximumContiguousSubsequenceSum(a, beg, mid);
	int rightSubProblem = maximumContiguousSubsequenceSum(a, mid + 1, end);

	int currentSum = 0, leftSum = 0, rightSum = 0;
	int i;

	for (i = mid; i >= beg; --i)
	{
		currentSum += a[i];

		if (leftSum < currentSum)
			leftSum = currentSum;
			
	}
	currentSum = 0;

	for (i = mid + 1; i <= end; ++i)
	{
		currentSum += a[i];

		if (rightSum < currentSum)
			rightSum = currentSum;
	}

	return (max(leftSubProblem, rightSubProblem, leftSum + rightSum));
}

int 
main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);

	int a[n];
	printf("Enter %d Integers \n", n);
	int i;
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	printf("Maximum Contiguous Subsequence Sum is %d \n", maximumContiguousSubsequenceSum(a, 0, n - 1));

	return (0);
}
