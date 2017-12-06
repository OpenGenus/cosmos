#include <stdio.h>

int reverseNumber(int n)
{
	int ans = 0;
	while (n != 0)
	{
		ans *= 10;
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main()
{
	int n;
	printf("Enter a number to reverse : ");
	scanf("%d" , &n);
	printf("Reverse of %d is %d" , n , reverseNumber(n));

	return 0;
}
