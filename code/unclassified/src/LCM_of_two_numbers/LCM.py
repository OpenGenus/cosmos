def __gcd__ ( a , b ):
    if a == 0:
        return b
    return __gcd__ ( b % a , a )


def __lcm__ ( a , b ):
    return (a * b) / __gcd__ ( a , b )


a = int ( input ( ) )
b = int ( input ( ) )  # type: int
print('LCM of' , a , 'and' , b , 'is' , __lcm__ ( a , b ))
