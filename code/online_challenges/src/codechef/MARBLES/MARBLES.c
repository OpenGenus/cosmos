#include <stdio.h>

int main(void) {
	
	int T, N, k;
	long long int ans=1;
	
	scanf("%d",&T);
	
	while(T>0)
	{
	    T--;
	    ans = 1;
	    
	    scanf("%d",&N);
	    scanf("%d",&k);
	    
	    if(N==k)
	    printf("%lld\n",ans);
	    else
	    {
	        N=N-1; 
	        k=k-1;
	        ans=1;
	        
	        if(k>N/2)
            k = N-k;
            
	        for(int i=0; i<k; i++)
	        {
	            ans = ans*(N-i);
	            ans = ans/(i+1);
	        }
	        printf("%lld\n", ans);
	    }
	}
	return 0;
}

