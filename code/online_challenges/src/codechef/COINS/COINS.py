a = {}

def dollar(n):
    if n <= 11:
        a[n] = n
        return a[n]
    if n in a:
        return a[n]
    a[n] = max(n, dollar(int(n / 2)) + dollar(int(n / 3)) + dollar(int(n / 4)))
    return a[n]

while True:
    try:
        n = int(input())
    except EOFError:
        break
    if n <= 11:
        print(n)
    else:
        print(dollar(n))
