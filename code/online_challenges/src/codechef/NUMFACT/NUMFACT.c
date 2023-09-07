#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* factorise(int* arr, int n, int max)
{
    int* count = (int*)malloc(sizeof(int) * (max + 1));
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 2; j <= sqrt(arr[i]); ++j)
        {
            while(arr[i] % j == 0)
            {
                arr[i] = (int)(arr[i] / j);
                *(count+j) += 1;
            }
        }
		
		if(arr[i] > 1)
			*(count + arr[i]) += 1;
    }
	    
	return count;
}

int main(void) {
	int t;
	
	scanf("%d", &t);
	
	while(t > 0)
	{
	    t--;
	    int n, ans = 1, max = 0;
		
	    scanf("%d", &n);
	    int arr[n];
	    
	    for(int i = 0; i < n; ++i)
	    {
	        scanf("%d", &arr[i]);
			
	        if(max < arr[i])
				max = arr[i];
	    }
	    
	    int* count = factorise(arr, n, max);
	    
	    for(int i = 0; i <= max; ++i)
	    {
	        if(*(count+i) != 0)
				ans = ans * (*(count + i) + 1);
	    }
	    printf("%d\n", ans);
	}
	return 0;
}


