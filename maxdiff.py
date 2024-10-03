t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    weights=list(map(int,input().split()))
    a=sorted(weights)
    sum1=0
    sum2=0
    k=min(k,n-k)
    for i in range(k):
        sum1=sum1+a[i]
    for i in range(k,n):
        sum2=sum2+a[i]
    
    print(sum2-sum1)