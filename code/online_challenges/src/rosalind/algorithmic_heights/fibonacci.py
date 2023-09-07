# Find the nth Fibonacci number
def fib(n):

    fibDict = dict()

    def f(n):

        if n in fibDict:
            return fibDict[n]
        else:
            if n == 0:
                fibDict[0] = 0
                return 0
            elif n == 1:
                fibDict[1] = 1
                return 1
            else:
                fibDict[n] = f(n-1) + f(n-2)
                return fibDict[n]

    return f(n)
