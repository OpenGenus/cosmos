#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int t;
	scanf("%d\n", &t);
	char* str = (char*)malloc(sizeof(char) * 1000001);
    
	while(t > 0)
	{
	    t--;
	    scanf("%s", str);
	    
        int n = strlen(str), f = 0;
        
        int* a = (int*)malloc(sizeof(int) * n);
              
        for(int i = 0; i < n; ++i)
        {
            *(a + i) = *(str + i) - 48;
            
            if(*(a + i) != 9)
            f = 1;
        }
        
        if(f == 0)
        {
            int* ans = (int*)calloc(sizeof(int), (n+1)); 
            
            *ans = 1;
            *(ans + n) = 1;
            
            for(int i = 0; i <= n; ++i)
            {
                printf("%d", *(ans + i));
            }
            printf("\n");
            
        }
	    else
	    {
          	
            int i, j, ini, inj, flag = 0;
              
            if(n % 2 == 0)
            {
			    inj = n / 2;
				ini = inj - 1;
            }
            else
            {
                inj= ini = (n / 2);
            }
             
            i = ini;
            j = inj;
            
            while(i >= 0 && j < n && *(a + i) == *(a + j))
            {
                i--;
                j++;
            }
              
            if(i == -1 && j == n)
            {
                flag = 1;
            }
            else
            {
                if(*(a + i) < *(a + j))
                    flag = 1;
            }
              
            if(flag == 1)
            {
                i = ini;
				j = inj;    
                  
				int c = 1;
			  
				while(c != 0 && i >= 0)
				{
					*(a + i) += c;
				  
					if(*(a + i) == 10)
					{
						*(a + i) = 0;
						c = 1;
					}
					else
					    c = 0;
					i--;
				}
            }
            i = ini;
			j = inj;
          	
            while(i >= 0 && j < n)
            {
          	    *(a + j) = *(a + i);
          	    i--; j++;
            }
            
	        for(int i = 0; i < n; ++i)
	        {
	            printf("%d", *(a + i));
	        }
	        printf("\n");
	    }
	}
	return 0;
}



