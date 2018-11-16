#Print series for a fixed value, i took the value 40000

def febno():
    a=0
    b=1
    d=0
    print(a)
    print(b)
    while(d<40,000):
        z=a+b 
        print(z)
        a=b
        b=z
        d=d+z                
febno()

# To print the series for a fixed number of elements
def febno(n):
    a=0
    b=1 
    count=0
    if n==1:
        print(a)
    elif(n==1):
        print(b)
    else:
        print(a)
        print(b)
        while(n>count):
            z=a+b 
            print(z)
            a=b
            b=z
            count+=1    
febno(int(input("enter the number of elements you want to print ion series")))
