l = [int(x) for x in input().split()]

def Qsort(a):
    if len(a)<=1:
        return a
    else:
        return Qsort([x for x in a[1:] if x<a[0]]) + [a[0]]+ Qsort([x for x in a[1:] if x>=a[0]])


print(Qsort(l))
