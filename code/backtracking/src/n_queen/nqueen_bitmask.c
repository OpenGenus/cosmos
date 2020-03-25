#include<stdio.h>
#define l long long int
l n,ans=0,DONE;
void solve(l rowMask,l ld,l rd){
    if(rowMask==DONE){
        ans++;
        return;
    }
    l safe=DONE &(~(rowMask|ld|rd));
    while(safe){
        l p=safe&(-safe);
        safe=safe-p;
        solve(rowMask|p,(ld|p)<<1,(rd|p)>>1);
    }
}
int main(){
    scanf("%lld",&n);
    DONE=(1<<n)-1;
    solve(0,0,0);
    printf("%lld",ans);
    return 0;
}
