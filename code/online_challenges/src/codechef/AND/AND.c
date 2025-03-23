#include <stdio.h>

int main(void) {
	
	int n;
	scanf("%d", &n);
	
	long a[n];
	for(int i = 0; i < n; ++i)
	{
	    scanf("%ld", &a[i]);
	}
	long ans = 0;
	for(int i = 0; i < 32; ++i)
	{
	    long t = (1 << i), count = 0;
	    
	    for(int j = 0; j < n; ++j)
	    {
	        if(a[j] & t)
	            count++;
	    }
	    
	    ans += ((count * (count - 1)) >> 1 ) * (1 << i);
	}
	printf("%ld\n", ans);
	return 0;
}