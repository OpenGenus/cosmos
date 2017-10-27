#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool issqaure(int n)
{
	int sroot=sqrt(n);
	if(sroot*sroot == n)
		return true;

	return false;
}

int main()
{
	printf("Enter the no. to be examined.\n");
	double n;
	scanf("%lf",&n);
	int root=issqaure(n);
	if(issqaure(n))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
