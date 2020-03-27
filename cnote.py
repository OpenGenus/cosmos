t=int(input())
for i in range (t):
    x,y,k,n=map(int,input().split())
    flag = False
    for i in range (n):
        p,c=map(int,input().split())
        if(p>=(x-y) and c<=k):
            flag = True

    if (flag == True):
        print("LuckyChef")
    else:
        print("UnluckyChef")