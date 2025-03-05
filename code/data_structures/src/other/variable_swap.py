#Different ways to swap 2 numbers
x=10
y=5

def swap1(x,y):#temporary variable
    temp=x
    x=y
    y=temp
    
def swap2(x,y):#Tuple swap and most elegant
    x,y=y,x


def swap3(x,y):#XOR swap
    x = x ^ y
    y = y ^ x
    x = x ^ y
