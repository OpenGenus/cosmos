#include <stdio.h>

int main(void) {
	
	int t, n, id, cid, ans;
	scanf("%d", &t);
	
	while(t--)
	{
	    scanf("%d", &n);
	    ans = 0;
	    for(int i = 0; i < n; i++)
	    {
	        scanf("%d %d", &id, &cid);
	        ans += id - cid;
	    }
	    printf("%d\n", ans);
	}
	return 0;
}
