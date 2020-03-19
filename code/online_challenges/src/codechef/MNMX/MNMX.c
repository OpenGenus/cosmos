#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long int N, i;
		scanf("%lld", &N);
		long long int a[N];
		for (i = 0; i < N; i++)
		{
			scanf("%lld", &a[i]);
		}
		long long int min = a[0];
		for (i = 0; i < N; i++)
		{
			if (a[i] < min)
			{
				min = a[i];
			}
		}
		printf("%lld\n", min * (N - 1));
	}
	return 0;
}
/*
Input
2
2
3 4
3
4 2 5

Output
3
4
*/
