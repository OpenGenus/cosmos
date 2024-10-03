#include <stdio.h>
#include <stdbool.h>

int main(){
    int q, i;
    scanf("%d", &q);
    
    bool bits[31];
    while(q--)
    {
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        
        int temp = x;
        for(i = 0; i < 31 ;i++)
        {
            if(temp & 1) bits[i] = true;
            
            else bits[i] = false;
            
            temp = temp / 2;
        }
        
        int ans = 0;
        for(i = 30; i >= 0 ;i--)
        {
            temp = 1 << i;
            if( bits[i] && (ans + temp - 1) < l ) ans += temp;
            
            else if( !bits[i] && (ans + temp) <= r) ans += temp;
        }
        
        printf("%d\n", (x ^ ans));
    }
}