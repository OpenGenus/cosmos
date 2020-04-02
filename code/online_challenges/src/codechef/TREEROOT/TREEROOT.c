#include <stdio.h>

int main(void) {
     	
    int t;
    scanf("%d", &t);
	
    while(t--)
    {      
	    int n, id, cid, i, ans = 0;
	    scanf("%d", &n);
		
	    for(i = 0; i < n; ++i)
	    {   
		    scanf("%d %d", &id, &cid);
		    ans += id - cid;
	    }
	    printf("%d\n", ans);
	}
	return 0;
}    
