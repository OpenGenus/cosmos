def base(a,y):
    ans=''
    while a>0 :
        ans+=str(a%y)
        a=a//y   
    ans=ans[::-1]
    return (ans)
    
def pal(x,b):
    x=str(x)
    if x!=x[::-1]:
        return (False)
    else:
        x=int(x)
        x=base(x,b)
        x=(str(x))
        if x!=x[::-1]:
            return (False)
        else:
            return (True)
               
a=int(1000000)
b=int(2)
sum=0
for i in range(1,a+1):
    if pal(i,b):
        sum+=i
    else:
        pass
print (sum)
    
