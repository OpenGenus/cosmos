#Part of Cosmos by OpenGenus Foundation

l = [int(x) for x in input().split()]

def Qsort(a):
    if len(a)<=1:
        return a
    else:
        l1 = Qsort([x for x in a[1:] if x<a[0]])
        l1 = l1 + [a[0]]
        l1 = l1 + Qsort([x for x in a[1:] if x>=a[0]])

        return (l1)
print(*Qsort(l))
