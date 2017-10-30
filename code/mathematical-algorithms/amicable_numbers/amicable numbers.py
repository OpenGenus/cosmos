print ("Amicable Numbers below 10000 are:")
for m in range(1,10000):
    x=m
    sum1=0
    sum2=0
    for i in range(1,x):
        if x%i==0:
            sum1+=i
    y=sum1
    for j in range(1,y):
        if y%j==0:
            sum2+=j
    if(sum2==x) and (x!=y):
        print(x)
