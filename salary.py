# Codechef Problem: SALARY
T=input("")
for i in range(t):
    a=input("")
    sal=list(map(int,raw_input("").split()))
    sal.sort()
    k=sum(sal)-(a)*sal[0]
    print k