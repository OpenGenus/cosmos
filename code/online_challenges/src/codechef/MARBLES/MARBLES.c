#include <stdio.h>

int main(void) {
	
   	int t;
	scanf("%d", &t);
	
	while(t > 0)
	{
	    t--;
		int n, k;
		long long int ans = 1;
		
	    scanf("%d", &n);
	    scanf("%d", &k);
	    
	    if(n == k)
	        printf("%lld\n", ans);
	    else
	    {
	        n--; 
	        k--;
	        ans = 1;
	        
	        if(k > n/2)
                k = n - k;
            
	        for(int i = 0; i < k; ++i)
	        {
	            ans *= n - i;
	            ans /= i + 1;
	        }
	        printf("%lld\n", ans);
	    }
	}
	return 0;
}
