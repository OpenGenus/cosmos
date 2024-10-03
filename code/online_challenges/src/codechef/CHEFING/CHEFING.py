mod=10**9+7

for _ in range(int(input())):
    n,k=map(int,input().split())
    if k<=n:
        print((k-1)%mod)
        continue
    x=(k-1)//(n-1)+1;
    if (x%2):
        d=(((x-1)//2)%mod)*(x%mod);
    else:
        d=((x//2)%mod)*((mod+x-1)%mod);
    d=d%mod
    x=x%mod
    k=(k-1)%mod
    n=(n-1)%mod
    ans=(k*x)%mod-(d*n)%mod;
    if ans<0:
        ans=mod+ans;
    print(ans%mod);