#include <stdio.h>

int main(void) {
	int t;
	
	scanf("%d", &t);
	
	while (t>0)
	{
	    t--;
	    
	    int n, count=0, sum=0, s; 
	    float e;
	    scanf("%d", &n);
	    
	    int a[n];
	    
	    for(int i = 0; i < n; ++i)
	    {
	        scanf("%d", &a[i]);
	        sum += a[i];
	        
	        if(a[i] == 0)
	        count++;
	    }
	    
	    if(sum < 100)
	        printf("NO\n");
	    else
	    {
	        if(sum == 100)
	            printf("YES\n");
	        else
	        {
	            n = n - count;
	            s = sum - n;
	            
	            if(s >= 100)
	                printf("NO\n");
	            else
	            {
	                e = (1-0.000001);
	                if((100 - s) <= n * e )
                        printf("YES\n");
                    else
                        printf("NO\n");
	            }
	        }
	    }
	}
	return 0;
}

