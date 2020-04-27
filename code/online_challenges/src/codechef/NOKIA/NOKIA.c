#include <stdio.h>

int wireLength(int n, char ch)
{
    if(n == 0)
        return 0;
        
    if(n == 1)
        return n + 1;
    
    if(ch == 'm')
        return n + 1 + wireLength(n / 2, ch) + wireLength(n - (n / 2) - 1, ch);
    else
        return n + 1 + wireLength(n - 1, ch);
}

int main(void) {
	int t;
	scanf("%d", &t);
	
	while(t > 0)
	{
	    int n, m;
	    scanf("%d %d", &n, &m);
	    
	    int min_length = wireLength(n, 'm');
        int max_length = wireLength(n, 'M');
        
        int ans = 0;
        
        if(m < min_length)
            ans = -1;
        else if(m > max_length)
            ans = m - max_length;
        else
            ans = 0;
                
        printf("%d\n", ans);
	    
	    t--;
	}
	return 0;
}